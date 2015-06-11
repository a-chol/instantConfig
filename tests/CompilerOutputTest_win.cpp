#include "CompilerOutputTest.h"
#include "ProjectSetup.h"
#include <Windows.h>


  std::tuple<unsigned int, std::string> CompilerOutputTest::build_test(const std::string& testName){
    SECURITY_ATTRIBUTES lSecuAttr;
    ZeroMemory( &lSecuAttr, sizeof(lSecuAttr) );
    lSecuAttr.nLength  = sizeof(SECURITY_ATTRIBUTES);
    lSecuAttr.bInheritHandle = true; 
    lSecuAttr.lpSecurityDescriptor = NULL;
    
    HANDLE lBuildProcInRead = NULL;//stdin read handle for the build process
    HANDLE lBuildProcInWrite = NULL;//stdin write handle for the test process
    HANDLE lBuildProcOutRead = NULL;//stdout read handle for the test process
    HANDLE lBuildProcOutWrite = NULL;//stdout write hndle for the build process
    
    //create the stdout pipe
    int lOutPipeCreateRes = CreatePipe(&lBuildProcOutRead, &lBuildProcOutWrite, &lSecuAttr, 0);
    if (lOutPipeCreateRes==0){
      throw std::string("could not create out pipe");
    }
    
    int lOutNotInherit = SetHandleInformation(lBuildProcOutRead, HANDLE_FLAG_INHERIT, 0);
    if (lOutNotInherit==0){
      throw std::string("could not set no inherit on out pipe");
    }
    
    //create the stdin pipe
    int lInPipeCreateRes = CreatePipe(&lBuildProcInRead, &lBuildProcInWrite, &lSecuAttr, 0);
    if (lInPipeCreateRes==0){
      throw std::string("could not create in pipe");
    }
    
    int lInNotInherit = SetHandleInformation(lBuildProcInWrite, HANDLE_FLAG_INHERIT, 0);
    if (lInNotInherit==0){
      throw std::string("could not set no inherit on in pipe");
    }
    
    //create the build process
    STARTUPINFO lStartInfo;
    ZeroMemory( &lStartInfo, sizeof(lStartInfo) );
    lStartInfo.cb = sizeof(lStartInfo);
    lStartInfo.hStdError = lBuildProcOutWrite;
    lStartInfo.hStdOutput = lBuildProcOutWrite;
    lStartInfo.hStdInput = lBuildProcInRead;
    lStartInfo.dwFlags |= STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW;
    lStartInfo.wShowWindow = SW_SHOWNORMAL;
      
    
    PROCESS_INFORMATION lProcInfo;
    ZeroMemory( &lProcInfo, sizeof(lProcInfo) );
    
    std::string lTestCommand = std::string(CmakeExecutable) + std::string(" --build . --clean-first --target ") + testName;
    
    int lRes = CreateProcess(NULL, const_cast<char*>(lTestCommand.c_str()), NULL, NULL, true, 0, NULL, TestProjectLocation, &lStartInfo, &lProcInfo);
    if (lRes==0){
      throw std::string("could not start compile process");
    }

    CloseHandle(lBuildProcOutWrite);
    CloseHandle(lBuildProcInRead);
    
    char lBuffer[1024] = { 0 };
    DWORD lReadCount = 0;
    bool lReadSuccess = false;
    std::string lBuildOutput;
    do{
      lReadSuccess = ReadFile(lBuildProcOutRead, lBuffer, 1024, &lReadCount, NULL);
      lBuildOutput.insert(lBuildOutput.end(), lBuffer, lBuffer + lReadCount);
    } while (lReadCount > 0 && lReadSuccess);

    WaitForSingleObject(lProcInfo.hProcess, 20000);

    DWORD lBuildProcExitCode = 0;
    bool lExitCodeRes = GetExitCodeProcess(lProcInfo.hProcess, &lBuildProcExitCode);
    if (!lExitCodeRes){
      throw std::string("could not get exit code");
    }
    
    CloseHandle(lProcInfo.hProcess);
    CloseHandle(lProcInfo.hThread);
    
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

