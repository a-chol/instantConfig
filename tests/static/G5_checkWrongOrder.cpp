#include "instantConfig.h"

using namespace icfg;

auto settingString = 
config(
  setting(
    ICFG_STR("setting"), string, check([](const std::string& str){return true;}, ICFG_STR("constraint"))
  )
);

int main(){

  return 0;
}