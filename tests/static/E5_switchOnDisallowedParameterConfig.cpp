#include "instantConfig.h"

using namespace icfg;

auto settingString = 
config(
  switchOn(
    ICFG_STR("switchValue"),
    config()
  )
);

int main(){

  return 0;
}