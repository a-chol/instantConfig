#include "instantConfig.h"

using namespace icfg;

auto emptyConfig = config();

auto settingString = 
config(
  switchOn(
    STG_NAME("switchValue"),
    caseOf(
      STG_NAME("caseOne"),
      setting(STG_NAME("settingName"),string),
      section(STG_NAME("section")),
      switchOn(STG_NAME("switchValue2")),
      include(emptyConfig),
      map(STG_NAME("map"))
    )
  )
);

int main(){

  return 0;
}