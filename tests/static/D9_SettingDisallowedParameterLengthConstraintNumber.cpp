#include "instantConfig.h"

using namespace icfg;

auto settingString = 
config(
  setting(
    STG_NAME("mySetting"),
    icfg::uint8,
    length>=5
  )
);

int main(){

  return 0;
}