#include "instantConfig.h"

using namespace icfg;

auto settingString = 
config(
  setting(
    ICFG_STR("mySetting"),
    string,
    setting(
      ICFG_STR("myInnerSetting"),
      string
    )
  )
);

int main(){

  return 0;
}