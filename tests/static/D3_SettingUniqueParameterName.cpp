#include "instantConfig.h"

using namespace icfg;

auto settingString = 
config(
  setting(
    ICFG_STR("mySetting"),
    ICFG_STR("mySetting2"),
    string
  )
);

int main(){

  return 0;
}