#include "instantConfig.h"

using namespace icfg;

auto settingString = 
config(
  setting(
    ICFG_STR("mySetting"),
    string,
    section(ICFG_STR("mySection"))
  )
);

int main(){

  return 0;
}