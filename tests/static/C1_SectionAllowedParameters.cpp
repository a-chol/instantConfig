#include "instantConfig.h"

using namespace icfg;

auto configEmpty = config();

auto settingString = 
config(
  section(ICFG_STR("caseOne"),
    setting(ICFG_STR("settingName"),string),
    section(ICFG_STR("section")),
    switchOn(ICFG_STR("switchValue2")),
    include(configEmpty),
    map(ICFG_STR("map"))
  )
);

int main(){

  return 0;
}