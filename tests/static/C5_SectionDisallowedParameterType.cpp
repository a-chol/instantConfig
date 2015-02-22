#include "instantConfig.h"

using namespace icfg;

auto settingString = 
config(
  section(
    STG_NAME("section"),
    
    string
    
  )
);

auto settingList = 
config(
  section(
    STG_NAME("section"),
    
    list(string)
    
  )
);

int main(){

  return 0;
}