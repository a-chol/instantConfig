#include "instantConfig.h"

using namespace icfg;

auto settingString = 
config(
  switchOn(
    STG_NAME("switchValue"),
    caseOf(
      STG_NAME("caseOne"),
      STG_NAME("caseTwo")
    )
  )
);

int main(){

  return 0;
}