#include "instantConfig.h"

using namespace icfg;

auto settingString = 
config(
  switchOn(
    ICFG_STR("switchValue"),
    setting(ICFG_STR("setting"),string)
  )
);

int main(){

  return 0;
}