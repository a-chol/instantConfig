#include "instantConfig.h"

using namespace icfg;


auto configEmpty = config();

auto configSetting = 
config(
  ICFG_STR("mySetting")
);

int main(){

  return 0;
}