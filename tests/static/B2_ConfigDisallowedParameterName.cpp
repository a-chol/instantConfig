#include "instantConfig.h"

using namespace icfg;


auto configEmpty = config();

auto configSetting = 
config(
  STG_NAME("mySetting")
);

int main(){

  return 0;
}