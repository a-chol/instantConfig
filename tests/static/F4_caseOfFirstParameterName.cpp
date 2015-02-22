#include "instantConfig.h"

using namespace icfg;

auto settingString = 
config(
  switchOn(
    STG_NAME("switchValue"),
    caseOf(
      setting(STG_NAME("caseOne"), string)
    )
  )
);

int main(){

  return 0;
}