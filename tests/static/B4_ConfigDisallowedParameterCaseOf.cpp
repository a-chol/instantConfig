#include "instantConfig.h"

using namespace icfg;

auto settingString = 
config(
  caseOf(STG_NAME("caseOne"))
);

int main(){

  return 0;
}