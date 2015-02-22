#include "instantConfig.h"

using namespace icfg;

auto configEmpty = config();

auto settingString = 
config(
  section(STG_NAME("caseOne"),
    setting(STG_NAME("settingName"),string),
    section(STG_NAME("section")),
    switchOn(STG_NAME("switchValue2")),
    include(configEmpty),
    map(STG_NAME("map"))
  )
);

int main(){

  return 0;
}