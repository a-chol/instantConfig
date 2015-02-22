#include "instantConfig.h"

using namespace icfg;


auto configEmpty = config();

auto configSetting = 
config(
  setting(STG_NAME("mySetting"), string)
);

auto configSection = 
config(
  section(STG_NAME("section"))
);

auto configSwitch = 
config(
  switchOn(STG_NAME("mySetting"), 
    caseOf(STG_NAME("val1"))
  )
);

auto configInclude = 
config(
  include(configEmpty)
);

auto configMap = 
config(
  map(STG_NAME("mapKey"))
);

int main(){

  return 0;
}