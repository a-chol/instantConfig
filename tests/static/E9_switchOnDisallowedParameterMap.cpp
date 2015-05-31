#include "instantConfig.h"

using namespace icfg;

auto settingString = 
config(
  switchOn(
    ICFG_STR("switchValue"),
    map(
      ICFG_STR("switchValue2")
    )
  )
);

int main(){

  return 0;
}