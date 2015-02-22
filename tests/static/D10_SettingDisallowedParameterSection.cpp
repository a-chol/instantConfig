#include "instantConfig.h"

using namespace icfg;

auto settingString = 
config(
  setting(
    STG_NAME("mySetting"),
    string,
    section(STG_NAME("mySection"))
  )
);

int main(){

  return 0;
}