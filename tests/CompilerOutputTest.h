
#ifndef COMPILEROUTPUTTEST_H
#define COMPILEROUTPUTTEST_H

#include "gtest/gtest.h"

#include <string>
#include <tuple>
#include <fstream>
#include <iostream>

class CompilerOutputTest : public ::testing::Test{
protected:
  std::tuple<unsigned int, std::string> build_test(const std::string& testName);

public:
  static ::testing::AssertionResult build_fails_with(const std::tuple<unsigned int, std::string>& pBuildOutput, const std::string& pExpected);
  static void output_result_if_failed(const std::string& result);

};

#endif //COMPILEROUTPUTTEST_H
