#include "instantConfig.h"

using namespace icfg;

auto settingString = 
config(
  section(
    STG_NAME("section"),
    
    caseOf(STG_NAME("caseOne"))
    
  )
);

int main(){

  return 0;
}