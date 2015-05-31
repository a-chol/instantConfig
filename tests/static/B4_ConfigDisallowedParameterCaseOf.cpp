#include "instantConfig.h"

using namespace icfg;

auto settingString = 
config(
  caseOf(ICFG_STR("caseOne"))
);

int main(){

  return 0;
}