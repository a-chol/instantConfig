#include "instantConfig.h"

using namespace icfg;

auto settingString = 
config(
  switchOn(
    ICFG_STR("switchValue"),
    caseOf(
      setting(ICFG_STR("caseOne"), string)
    )
  )
);

int main(){

  return 0;
}