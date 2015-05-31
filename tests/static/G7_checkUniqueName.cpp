#include "instantConfig.h"

using namespace icfg;

auto settingString = 
config(
  setting(
    ICFG_STR("setting"), string, check(ICFG_STR("constraint"), ICFG_STR("constraint2"), [](const std::string& str){return true;})
  )
);

int main(){

  return 0;
}