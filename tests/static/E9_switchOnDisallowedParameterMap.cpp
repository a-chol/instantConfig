#include "instantConfig.h"

using namespace icfg;

auto settingString = 
config(
  switchOn(
    STG_NAME("switchValue"),
    map(
      STG_NAME("switchValue2")
    )
  )
);

int main(){

  return 0;
}