#include "instantConfig.h"

using namespace icfg;

auto settingString = 
config(
  switchOn(
    caseOf(
      ICFG_STR("caseOne")
    ),
    ICFG_STR("switchValue")
  )
);

int main(){

  return 0;
}