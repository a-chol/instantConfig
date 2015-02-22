#include "instantConfig.h"

using namespace icfg;

auto settingString = 
config(
  setting(
    STG_NAME("mySetting"),
    string,
    length>5
  )
);

auto settingList = 
config(
  setting(
    STG_NAME("mySetting"),
    list(string),
    length>5
  )
);

int main(){

  return 0;
}