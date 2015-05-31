#include "instantConfig.h"

using namespace icfg;

auto forbiddenSetting = 
config(
  setting(
    ICFG_STR("setting"), string, check(setting(ICFG_STR("setting"), string))
  )
);

auto forbiddenSection = 
config(
  setting(
    ICFG_STR("setting"), string, check(section(ICFG_STR("setting")))
  )
);

auto forbiddenSwitchOn = 
config(
  setting(
    ICFG_STR("setting"), string, check(switchOn(ICFG_STR("setting")))
  )
);

auto forbiddenCaseOf = 
config(
  setting(
    ICFG_STR("setting"), string, check(caseOf(ICFG_STR("setting")))
  )
);

auto forbiddenMap = 
config(
  setting(
    ICFG_STR("setting"), string, check(map(ICFG_STR("setting")))
  )
);

auto forbiddenList = 
config(
  setting(
    ICFG_STR("setting"), string, check(list(string))
  )
);

auto forbiddenString = 
config(
  setting(
    ICFG_STR("setting"), string, check(string)
  )
);

auto forbiddenConfig = 
config(
  setting(
    ICFG_STR("setting"), string, check(config())
  )
);

auto forbiddenLength = 
config(
  setting(
    ICFG_STR("setting"), string, check(length<2)
  )
);

int main(){

  return 0;
}