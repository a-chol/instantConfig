#include "instantConfig.h"

using namespace icfg;

auto includeCfg = config();

auto settingString = 
config(
  setting(
    ICFG_STR("mySetting"),
    string,
    include(includeCfg)
  )
);

int main(){

  return 0;
}