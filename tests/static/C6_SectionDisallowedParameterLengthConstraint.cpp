#include "instantConfig.h"

using namespace icfg;

auto sectionTest = 
config(
  section(
    STG_NAME("mySetting"),
    length>5
  )
);

int main(){

  return 0;
}