#include "instantConfig.h"

using namespace icfg;

auto settingString = 
config(
  setting(
    ICFG_STR("mySetting"),
    list(string),
    length>=5
  )
);

int main(){

  return 0;
}