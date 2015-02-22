#include "instantConfig.h"

using namespace icfg;

auto settingString = 
config(
  setting(
    STG_NAME("mySetting"),
    string,
    switchOn(STG_NAME("mySection"))
  )
);

int main(){

  return 0;
}