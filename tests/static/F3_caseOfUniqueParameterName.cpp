#include "instantConfig.h"

using namespace icfg;

auto settingString = 
config(
  switchOn(
    ICFG_STR("switchValue"),
    caseOf(
      ICFG_STR("caseOne"),
      ICFG_STR("caseTwo")
    )
  )
);

int main(){

  return 0;
}