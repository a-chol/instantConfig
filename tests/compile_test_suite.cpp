
#include "gtest/gtest.h"

#include "ProjectSetup.h"

#include "CompilerOutputTest.h"

/**
Canonical
*/

TEST_F(CompilerOutputTest, A1_Canonical){
  auto testResult = build_test(std::string("A1_Canonical"));
  EXPECT_EQ(0, std::get<0>(testResult));
  output_result_if_failed(std::get<1>(testResult));
}

TEST_F(CompilerOutputTest, B1_ConfigAllowedParameters){
  auto testResult = build_test(std::string("B1_ConfigAllowedParameters"));
  
  EXPECT_EQ(0, std::get<0>(testResult));
  output_result_if_failed(std::get<1>(testResult));
}

TEST_F(CompilerOutputTest, B2_ConfigDisallowedParameterName){
  auto testResult = build_test(std::string("B2_ConfigDisallowedParameterName"));
  
  EXPECT_TRUE(CompilerOutputTest::build_fails_with(testResult, "Forbidden settingName parameter to config function."));
  output_result_if_failed(std::get<1>(testResult));
}

TEST_F(CompilerOutputTest, B3_ConfigDisallowedParameterType){
  auto testResult = build_test(std::string("B3_ConfigDisallowedParameterType"));
  
  EXPECT_TRUE(CompilerOutputTest::build_fails_with(testResult, "Forbidden string parameter to config function."));
  output_result_if_failed(std::get<1>(testResult));
}

TEST_F(CompilerOutputTest, B4_ConfigDisallowedParameterCaseOf){
  auto testResult = build_test(std::string("B4_ConfigDisallowedParameterCaseOf"));
  
  EXPECT_TRUE(CompilerOutputTest::build_fails_with(testResult, "Forbidden caseOf parameter to config function."));
  output_result_if_failed(std::get<1>(testResult));
}

TEST_F(CompilerOutputTest, B5_ConfigDisallowedParameterLengthConstraint){
  auto testResult = build_test(std::string("B5_ConfigDisallowedParameterLengthConstraint"));
  
  EXPECT_TRUE(CompilerOutputTest::build_fails_with(testResult, "Forbidden length constraint parameter to config function."));
  output_result_if_failed(std::get<1>(testResult));
}

TEST_F(CompilerOutputTest, C1_SectionAllowedParameters){
  auto testResult = build_test(std::string("C1_SectionAllowedParameters"));
  
  EXPECT_EQ(0, std::get<0>(testResult));
  output_result_if_failed(std::get<1>(testResult));
}

TEST_F(CompilerOutputTest, C2_SectionRequiredParameterName){
  auto testResult = build_test(std::string("C2_SectionRequiredParameterName"));
  
  EXPECT_TRUE(CompilerOutputTest::build_fails_with(testResult, "missing required parameter settingName in section"));
  output_result_if_failed(std::get<1>(testResult));
}

TEST_F(CompilerOutputTest, C3_SectionUniqueParameterName){
  auto testResult = build_test(std::string("C3_SectionUniqueParameterName"));
  
  EXPECT_TRUE(CompilerOutputTest::build_fails_with(testResult, "parameter settingName should be unique for section"));
  output_result_if_failed(std::get<1>(testResult));
}

TEST_F(CompilerOutputTest, C4_SectionDisallowedParameterCaseOf){
  auto testResult = build_test(std::string("C4_SectionDisallowedParameterCaseOf"));
  
  EXPECT_TRUE(CompilerOutputTest::build_fails_with(testResult, "Forbidden caseOf parameter to section function."));
  output_result_if_failed(std::get<1>(testResult));
}

TEST_F(CompilerOutputTest, C5_SectionDisallowedParameterType){
  auto testResult = build_test(std::string("C5_SectionDisallowedParameterType"));
  
  EXPECT_TRUE(CompilerOutputTest::build_fails_with(testResult, "Forbidden string parameter to section function."));
  EXPECT_TRUE(CompilerOutputTest::build_fails_with(testResult, "Forbidden list parameter to section function."));
  output_result_if_failed(std::get<1>(testResult));
}

TEST_F(CompilerOutputTest, C6_SectionDisallowedParameterLengthConstraint){
  auto testResult = build_test(std::string("C6_SectionDisallowedParameterLengthConstraint"));
  
  EXPECT_TRUE(CompilerOutputTest::build_fails_with(testResult, "Forbidden length constraint parameter to section function."));
  output_result_if_failed(std::get<1>(testResult));
}

TEST_F(CompilerOutputTest, D1_SettingAllowedParameters){
  auto testResult = build_test(std::string("D1_SettingAllowedParameters"));
  EXPECT_EQ(0, std::get<0>(testResult));
  output_result_if_failed(std::get<1>(testResult));
}

TEST_F(CompilerOutputTest, D2_SettingRequiredParameterName){
  auto testResult = build_test(std::string("D2_SettingRequiredParameterName"));
  
  EXPECT_TRUE(CompilerOutputTest::build_fails_with(testResult, "missing required parameter settingName in setting"));
  output_result_if_failed(std::get<1>(testResult));
}

TEST_F(CompilerOutputTest, D3_SettingUniqueParameterName){
  auto testResult = build_test(std::string("D3_SettingUniqueParameterName"));
  
  EXPECT_TRUE(CompilerOutputTest::build_fails_with(testResult, "parameter settingName should be unique for setting"));
  output_result_if_failed(std::get<1>(testResult));
}

TEST_F(CompilerOutputTest, D4_SettingRequiredParameterType){
  auto testResult = build_test(std::string("D4_SettingRequiredParameterType"));
  
  EXPECT_TRUE(CompilerOutputTest::build_fails_with(testResult, "missing required type parameter in setting definition"));
  output_result_if_failed(std::get<1>(testResult));
}

TEST_F(CompilerOutputTest, D5_SettingUniqueParameterType){
  auto testResult = build_test(std::string("D5_SettingUniqueParameterType"));
  
  EXPECT_TRUE(CompilerOutputTest::build_fails_with(testResult, "type parameter should be unique for setting definition"));
  output_result_if_failed(std::get<1>(testResult));
}

TEST_F(CompilerOutputTest, D6_SettingDisallowedParameterCaseOf){
  auto testResult = build_test(std::string("D6_SettingDisallowedParameterCaseOf"));
  
  EXPECT_TRUE(CompilerOutputTest::build_fails_with(testResult, "Forbidden caseOf parameter to setting function."));
  output_result_if_failed(std::get<1>(testResult));
}

TEST_F(CompilerOutputTest, D7_SettingAllowedParameterLengthConstraintForString){
  auto testResult = build_test(std::string("D7_SettingAllowedParameterLengthConstraintForString"));
  
  EXPECT_EQ(0, std::get<0>(testResult));
  output_result_if_failed(std::get<1>(testResult));
}

TEST_F(CompilerOutputTest, D8_SettingAllowedParameterLengthConstraintForList){
  auto testResult = build_test(std::string("D8_SettingAllowedParameterLengthConstraintForList"));
  
  EXPECT_EQ(0, std::get<0>(testResult));
  output_result_if_failed(std::get<1>(testResult));
}

TEST_F(CompilerOutputTest, D9_SettingDisallowedParameterLengthConstraintNumber){
  auto testResult = build_test(std::string("D9_SettingDisallowedParameterLengthConstraintNumber"));
  
  EXPECT_TRUE(CompilerOutputTest::build_fails_with(testResult, "length is not a valid constraint for numbers setting type."));
  output_result_if_failed(std::get<1>(testResult));
}

TEST_F(CompilerOutputTest, D10_SettingDisallowedParameterSection){
  auto testResult = build_test(std::string("D10_SettingDisallowedParameterSection"));
  
  EXPECT_TRUE(CompilerOutputTest::build_fails_with(testResult, "Forbidden section parameter to setting function."));
  output_result_if_failed(std::get<1>(testResult));
}

TEST_F(CompilerOutputTest, D11_SettingDisallowedParameterSwitchOn){
  auto testResult = build_test(std::string("D11_SettingDisallowedParameterSwitchOn"));
  
  EXPECT_TRUE(CompilerOutputTest::build_fails_with(testResult, "Forbidden switchOn parameter to setting function."));
  output_result_if_failed(std::get<1>(testResult));
}

TEST_F(CompilerOutputTest, D12_SettingDisallowedParameterInclude){
  auto testResult = build_test(std::string("D12_SettingDisallowedParameterInclude"));
  
  EXPECT_TRUE(CompilerOutputTest::build_fails_with(testResult, "Forbidden include parameter to setting function."));
  output_result_if_failed(std::get<1>(testResult));
}

TEST_F(CompilerOutputTest, D13_SettingDisallowedParameterSetting){
  auto testResult = build_test(std::string("D13_SettingDisallowedParameterSetting"));
  
  EXPECT_TRUE(CompilerOutputTest::build_fails_with(testResult, "Forbidden setting parameter to setting function."));
  output_result_if_failed(std::get<1>(testResult));
}

TEST_F(CompilerOutputTest, E1_switchOnAllowedParameters){
  auto testResult = build_test(std::string("E1_switchOnAllowedParameters"));
  
  EXPECT_EQ(0, std::get<0>(testResult));
  output_result_if_failed(std::get<1>(testResult));
}

TEST_F(CompilerOutputTest, E2_switchOnRequiredParameterName){
  auto testResult = build_test(std::string("E2_switchOnRequiredParameterName"));
  
  EXPECT_TRUE(CompilerOutputTest::build_fails_with(testResult, "missing required parameter settingName in switchOn"));
  output_result_if_failed(std::get<1>(testResult));
}

TEST_F(CompilerOutputTest, E3_switchOnUniqueParameterName){
  auto testResult = build_test(std::string("E3_switchOnUniqueParameterName"));
  
  EXPECT_TRUE(CompilerOutputTest::build_fails_with(testResult, "parameter settingName should be unique for switchOn"));
  output_result_if_failed(std::get<1>(testResult));
}

TEST_F(CompilerOutputTest, E4_switchOnDisallowedParameterType){
  auto testResult = build_test(std::string("E4_switchOnDisallowedParameterType"));
  
  EXPECT_TRUE(CompilerOutputTest::build_fails_with(testResult, "Forbidden string parameter to switchOn function."));
  output_result_if_failed(std::get<1>(testResult));
}

TEST_F(CompilerOutputTest, E5_switchOnDisallowedParameterConfig){
  auto testResult = build_test(std::string("E5_switchOnDisallowedParameterConfig"));
  
  EXPECT_TRUE(CompilerOutputTest::build_fails_with(testResult, "Forbidden config parameter to switchOn function."));
  output_result_if_failed(std::get<1>(testResult));
}

TEST_F(CompilerOutputTest, E6_switchOnDisallowedParameterSection){
  auto testResult = build_test(std::string("E6_switchOnDisallowedParameterSection"));
  
  EXPECT_TRUE(CompilerOutputTest::build_fails_with(testResult, "Forbidden section parameter to switchOn function."));
  output_result_if_failed(std::get<1>(testResult));
}

TEST_F(CompilerOutputTest, E7_switchOnDisallowedParameterSetting){
  auto testResult = build_test(std::string("E7_switchOnDisallowedParameterSetting"));
  
  EXPECT_TRUE(CompilerOutputTest::build_fails_with(testResult, "Forbidden setting parameter to switchOn function."));
  output_result_if_failed(std::get<1>(testResult));
}

TEST_F(CompilerOutputTest, E8_switchOnDisallowedParameterSwitchOn){
  auto testResult = build_test(std::string("E8_switchOnDisallowedParameterSwitchOn"));
  
  EXPECT_TRUE(CompilerOutputTest::build_fails_with(testResult, "Forbidden switchOn parameter to switchOn function."));
  output_result_if_failed(std::get<1>(testResult));
}

TEST_F(CompilerOutputTest, E9_switchOnDisallowedParameterMap){
  auto testResult = build_test(std::string("E9_switchOnDisallowedParameterMap"));
  
  EXPECT_TRUE(CompilerOutputTest::build_fails_with(testResult, "Forbidden map parameter to switchOn function."));
  output_result_if_failed(std::get<1>(testResult));
}

TEST_F(CompilerOutputTest, E10_switchOnDisallowedParameterLengthConstraint){
  auto testResult = build_test(std::string("E10_switchOnDisallowedParameterLengthConstraint"));
  
  EXPECT_TRUE(CompilerOutputTest::build_fails_with(testResult, "Forbidden length constraint parameter to switchOn function."));
  output_result_if_failed(std::get<1>(testResult));
}

TEST_F(CompilerOutputTest, E11_switchOnFirstParameterName){
  auto testResult = build_test(std::string("E11_switchOnFirstParameterName"));
  
  EXPECT_TRUE(CompilerOutputTest::build_fails_with(testResult, "parameter 0 to switchOn should be settingName"));
  output_result_if_failed(std::get<1>(testResult));
}

TEST_F(CompilerOutputTest, F1_caseOfAllowedParameters){
  auto testResult = build_test(std::string("F1_caseOfAllowedParameters"));
  
  EXPECT_EQ(0, std::get<0>(testResult));
  output_result_if_failed(std::get<1>(testResult));
}

TEST_F(CompilerOutputTest, F2_caseOfRequiredParameterName){
  auto testResult = build_test(std::string("F2_caseOfRequiredParameterName"));
  
  EXPECT_TRUE(CompilerOutputTest::build_fails_with(testResult, "missing required parameter settingName in caseOf"));
  output_result_if_failed(std::get<1>(testResult));
}

TEST_F(CompilerOutputTest, F3_caseOfUniqueParameterName){
  auto testResult = build_test(std::string("F3_caseOfUniqueParameterName"));
  
  EXPECT_TRUE(CompilerOutputTest::build_fails_with(testResult, "parameter settingName should be unique for caseOf"));
  output_result_if_failed(std::get<1>(testResult));
}

TEST_F(CompilerOutputTest, F4_caseOfFirstParameterName){
  auto testResult = build_test(std::string("F4_caseOfFirstParameterName"));
  
  EXPECT_TRUE(CompilerOutputTest::build_fails_with(testResult, "parameter 0 to caseOf should be settingName"));
  output_result_if_failed(std::get<1>(testResult));
}

TEST_F(CompilerOutputTest, G1_checkValid){
  auto testResult = build_test(std::string("G1_checkValid"));
  
  EXPECT_EQ(0, std::get<0>(testResult));
  output_result_if_failed(std::get<1>(testResult));
}

TEST_F(CompilerOutputTest, G2_checkDisallowedParameters){
  auto testResult = build_test(std::string("G2_checkDisallowedParameters"));
  
  EXPECT_TRUE(CompilerOutputTest::build_fails_with(testResult, "Forbidden setting parameter to check function."));
  EXPECT_TRUE(CompilerOutputTest::build_fails_with(testResult, "Forbidden section parameter to check function."));
  EXPECT_TRUE(CompilerOutputTest::build_fails_with(testResult, "Forbidden switchOn parameter to check function."));
  EXPECT_TRUE(CompilerOutputTest::build_fails_with(testResult, "Forbidden caseOf parameter to check function."));
  EXPECT_TRUE(CompilerOutputTest::build_fails_with(testResult, "Forbidden map parameter to check function."));
  EXPECT_TRUE(CompilerOutputTest::build_fails_with(testResult, "Forbidden list parameter to check function."));
  EXPECT_TRUE(CompilerOutputTest::build_fails_with(testResult, "Forbidden string parameter to check function."));
  EXPECT_TRUE(CompilerOutputTest::build_fails_with(testResult, "Forbidden config parameter to check function."));
  EXPECT_TRUE(CompilerOutputTest::build_fails_with(testResult, "Forbidden length constraint parameter to check function."));
  output_result_if_failed(std::get<1>(testResult));
}

TEST_F(CompilerOutputTest, G3_checkNoName){
  auto testResult = build_test(std::string("G3_checkNoName"));
  
  EXPECT_TRUE(CompilerOutputTest::build_fails_with(testResult, "missing required parameter settingName in check"));
  output_result_if_failed(std::get<1>(testResult));
}

TEST_F(CompilerOutputTest, G4_checkNoLambda){
  auto testResult = build_test(std::string("G4_checkNoLambda"));
  
  EXPECT_TRUE(CompilerOutputTest::build_fails_with(testResult, "missing required functor parameter in check function"));
  output_result_if_failed(std::get<1>(testResult));
}

TEST_F(CompilerOutputTest, G5_checkWrongOrder){
  auto testResult = build_test(std::string("G5_checkWrongOrder"));
  
  EXPECT_TRUE(CompilerOutputTest::build_fails_with(testResult, "parameter 0 to check should be settingName"));
  output_result_if_failed(std::get<1>(testResult));
}

TEST_F(CompilerOutputTest, G6_checkWrongParameterType){
  auto testResult = build_test(std::string("G6_checkWrongParameterType"));
  
  EXPECT_TRUE(CompilerOutputTest::build_fails_with(testResult, "constraint input parameter doesn't match the setting's result type"));
  output_result_if_failed(std::get<1>(testResult));
}

TEST_F(CompilerOutputTest, G7_checkUniqueName){
  auto testResult = build_test(std::string("G7_checkUniqueName"));
  
  EXPECT_TRUE(CompilerOutputTest::build_fails_with(testResult, "parameter settingName should be unique for check"));
  output_result_if_failed(std::get<1>(testResult));
}





