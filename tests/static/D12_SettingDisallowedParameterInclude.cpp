#include "instantConfig.h"

using namespace icfg;

auto includeCfg = config();

auto settingString = 
config(
  setting(
    STG_NAME("mySetting"),
    string,
    include(includeCfg)
  )
);

int main(){

  return 0;
}