#include "instantConfig.h"

using namespace icfg;

auto settingString = 
config(
  setting(
    STG_NAME("mySetting"),
    string,
    caseOf(STG_NAME("myCase"))
  )
);

int main(){

  return 0;
}