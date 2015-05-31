#include "instantConfig.h"

using namespace icfg;

auto myConfig = 
config(
  setting(ICFG_STR("mySetting"), string)
);

int main(){

  return 0;
}