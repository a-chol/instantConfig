#include "instantConfig.h"

using namespace icfg;

auto settingString = 
config(
  setting(
    STG_NAME("mySetting"),
    STG_NAME("mySetting2"),
    string
  )
);

int main(){

  return 0;
}