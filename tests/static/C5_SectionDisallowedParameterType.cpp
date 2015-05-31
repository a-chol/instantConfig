#include "instantConfig.h"

using namespace icfg;

auto settingString = 
config(
  section(
    ICFG_STR("section"),
    
    string
    
  )
);

auto settingList = 
config(
  section(
    ICFG_STR("section"),
    
    list(string)
    
  )
);

int main(){

  return 0;
}