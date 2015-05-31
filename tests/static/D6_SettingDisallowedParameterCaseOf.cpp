#include "instantConfig.h"

using namespace icfg;

auto settingString = 
config(
  setting(
    ICFG_STR("mySetting"),
    string,
    caseOf(ICFG_STR("myCase"))
  )
);

int main(){

  return 0;
}