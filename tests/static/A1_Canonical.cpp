#include "instantConfig.h"

using namespace icfg;

auto myConfig = 
config(
  setting(STG_NAME("mySetting"), string)
);

int main(){

  return 0;
}