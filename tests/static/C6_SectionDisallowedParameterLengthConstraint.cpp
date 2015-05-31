#include "instantConfig.h"

using namespace icfg;

auto sectionTest = 
config(
  section(
    ICFG_STR("mySetting"),
    length>5
  )
);

int main(){

  return 0;
}