#include "instantConfig.h"

using namespace icfg;

auto settingString = 
config(
  switchOn(
    STG_NAME("switchValue"),
    section(STG_NAME("section"))
  )
);

int main(){

  return 0;
}