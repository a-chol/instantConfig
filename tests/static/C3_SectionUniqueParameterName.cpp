#include "instantConfig.h"

using namespace icfg;

auto settingString = 
config(
  section(
    ICFG_STR("section"),
    ICFG_STR("sectionTwo")
    
  )
);

int main(){

  return 0;
}