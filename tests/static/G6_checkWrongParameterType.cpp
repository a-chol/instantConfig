#include "instantConfig.h"

using namespace icfg;

auto settingString = 
config(
  setting(
    ICFG_STR("setting"), string, check(ICFG_STR("constraint"), [](const std::vector<std::string>& str){return true;})
  )
);

int main(){

  return 0;
}