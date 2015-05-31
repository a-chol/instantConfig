#include "instantConfig.h"

using namespace icfg;

auto settingString = 
config(
  setting(
    ICFG_STR("mySetting"),
    string,
    switchOn(ICFG_STR("mySection"))
  )
);

int main(){

  return 0;
}