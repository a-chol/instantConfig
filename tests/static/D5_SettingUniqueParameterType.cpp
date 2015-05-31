#include "instantConfig.h"

using namespace icfg;

auto settingString = 
config(
  setting(
    ICFG_STR("mySetting"),
    string,
    list(string)
  )
);

int main(){

  return 0;
}