#include "instantConfig.h"

using namespace icfg;

auto settingString = 
config(
  switchOn(
    ICFG_STR("switchValue"),
    section(ICFG_STR("section"))
  )
);

int main(){

  return 0;
}