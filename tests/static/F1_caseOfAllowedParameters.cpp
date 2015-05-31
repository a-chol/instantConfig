#include "instantConfig.h"

using namespace icfg;

auto emptyConfig = config();

auto settingString = 
config(
  switchOn(
    ICFG_STR("switchValue"),
    caseOf(
      ICFG_STR("caseOne"),
      setting(ICFG_STR("settingName"),string),
      section(ICFG_STR("section")),
      switchOn(ICFG_STR("switchValue2")),
      include(emptyConfig),
      map(ICFG_STR("map"))
    )
  )
);

int main(){

  return 0;
}