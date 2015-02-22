#include "instantConfig.h"

using namespace icfg;

auto settingString = 
config(
  switchOn(
    STG_NAME("switchValue"),
    switchOn(
      STG_NAME("switchValue2"),
      string
    )
  )
);

int main(){

  return 0;
}