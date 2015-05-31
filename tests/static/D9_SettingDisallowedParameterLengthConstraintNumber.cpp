#include "instantConfig.h"

using namespace icfg;

auto settingString = 
config(
  setting(
    ICFG_STR("mySetting"),
    icfg::uint8,
    length>=5
  )
);

int main(){

  return 0;
}