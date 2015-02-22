#include "instantConfig.h"

using namespace icfg;

auto settingString = 
config(
  setting(
    STG_NAME("mySetting"),
    string,
    setting(
      STG_NAME("myInnerSetting"),
      string
    )
  )
);

int main(){

  return 0;
}