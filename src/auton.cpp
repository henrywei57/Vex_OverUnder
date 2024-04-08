#include "robot-config.h"
#include "autons/auton.h"
#include "main.h"
#include "autons/auton_functions.h"
using namespace vex;
using namespace auton;

void test(){
    it.setHeading(0, degrees);
    // driveAndTurn(2, 0);
    turnToAngle(90, 100, 3000);
    
}
void far(){

}