#include "instantConfig.h"

using namespace icfg;

auto settingString = 
config(
  setting(
    ICFG_STR("setting"), string, check(ICFG_STR("constraint"))
  )
);

int main(){

  return 0;
}