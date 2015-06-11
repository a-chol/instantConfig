#include "CompilerOutputTest.h"

#include <ProjectSetup.h>

  std::tuple<unsigned int, std::string> CompilerOutputTest::build_test(const std::string& testName){
    
    
    std::string lTestCommand = std::string("cmake --build . --clean-first --target ") + testName;
    int lPipes[2];
    if (pipe(lPipes)==-1){
      throw std::string("could not create pipes");
    }
    
    pid_t lChildPid = fork();
    if (lChildPid==-1){
      throw std::string("could not fork compile process"); 
    } else if (lChildPid==0){
      close(lPipes[0]);
      dup2(lPipes[1], STDOUT_FILENO);
      chdir(TestProjectLocation);
      execlp(CmakeExecutable, CmakeExecutable, "--build", ".", "--clean-first", "--target", testName.c_str(), (char*)NULL);
      
      exit(-1);
    }

    
    close(lPipes[1]);
    char lBuffer[1024] = { 0 };
    ssize_t lReadCount = 0;
    std::string lBuildOutput;
    do{
      lReadCount = read(lPipes[0], lBuffer, 1024);
      if (lReadCount>0){
        lBuildOutput.insert(lBuildOutput.end(), lBuffer, lBuffer + lReadCount);
      }
    }while(lReadCount>0);

    int lBuildProcExitCode = 0;
    waitpid(lChildPid, &lBuildProcExitCode, 0);
    
    close(lPipes[0]);
    
    return std::tuple<unsigned int, std::string>(lBuildProcExitCode, lBuildOutput);
  }

  ::testing::AssertionResult CompilerOutputTest::build_fails_with(const std::tuple<unsigned int, std::string>& pBuildOutput, const std::string& pExpected){
    if (std::get<0>(pBuildOutput)==0){
      return ::testing::AssertionFailure() 
        << "build failure expected";
    }
    if (std::get<1>(pBuildOutput).find(pExpected) != std::string::npos){
      return ::testing::AssertionSuccess();
    } else {
      return ::testing::AssertionFailure() 
        << "static_assert failure expected";
    }
  }
  
  void CompilerOutputTest::output_result_if_failed(const std::string& result){
    if (::testing::Test::HasFailure()){
      const ::testing::TestInfo* const test_info =::testing::UnitTest::GetInstance()->current_test_info();
      std::ofstream report(std::string("failure_reports_")+test_info->test_case_name()+"."+test_info->name()+".txt");
      report.write(result.c_str(), result.size());
    }
  }

