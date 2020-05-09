#include "hotaru.h"

hotaru hotaruA = hotaru(3, GENJI2); 
hotaru hotaruB = hotaru(5, GENJI2);
hotaru hotaruC = hotaru(6, GENJI2);
hotaru hotaruD = hotaru(9, GENJI2);
hotaru hotaruE = hotaru(10, GENJI2);
hotaru hotaruF = hotaru(11, GENJI2);

void setup() {
}

void loop() {
  hotaruA.stateCheck();
  hotaruB.stateCheck();
  hotaruC.stateCheck();
  hotaruD.stateCheck();
  hotaruE.stateCheck();
  hotaruF.stateCheck();
}
