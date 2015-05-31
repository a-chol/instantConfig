#include "instantConfig.h"

using namespace icfg;

auto settingString = 
config(
  switchOn(
    ICFG_STR("switchValue"),
    switchOn(
      ICFG_STR("switchValue2"),
      string
    )
  )
);

int main(){

  return 0;
}