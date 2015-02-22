#include "instantConfig.h"

using namespace icfg;

auto settingString = 
config(
  switchOn(
    STG_NAME("switchValue"),
    caseOf(
      STG_NAME("caseOne")
    )
  )
);

int main(){

  return 0;
}