#include "instantConfig.h"

using namespace icfg;

auto settingString = 
config(
  section(
    ICFG_STR("section"),
    
    caseOf(ICFG_STR("caseOne"))
    
  )
);

int main(){

  return 0;
}