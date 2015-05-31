#include "instantConfig.h"

using namespace icfg;


auto configEmpty = config();

auto configSetting = 
config(
  setting(ICFG_STR("mySetting"), string)
);

auto configSection = 
config(
  section(ICFG_STR("section"))
);

auto configSwitch = 
config(
  switchOn(ICFG_STR("mySetting"), 
    caseOf(ICFG_STR("val1"))
  )
);

auto configInclude = 
config(
  include(configEmpty)
);

auto configMap = 
config(
  map(ICFG_STR("mapKey"))
);

int main(){

  return 0;
}