#include "instantConfig.h"

using namespace icfg;

auto settingString = 
config(
  switchOn(
    STG_NAME("switchValue"),
    setting(STG_NAME("setting"),string)
  )
);

int main(){

  return 0;
}