#include "instantConfig.h"

using namespace icfg;

auto settingString = 
config(
  switchOn(
    caseOf(
      STG_NAME("caseOne")
    ),
    STG_NAME("switchValue")
  )
);

int main(){

  return 0;
}