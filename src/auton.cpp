#include "autons/auton.h"
#include "main.h"
#include "autons/auton_functions.h"
using namespace vex;
using namespace auton;

void test(){
    turnToAngle(90, 100);
    turnToAngle(180, 100);
    turnToAngle(0, 100);
    driveAndTurn(0.5, 90);
    driveAndTurn(0.5, -180);
    driveAndTurn(0.5, -90);
    driveAndTurn(0.5, 0);
    driveAndTurn(1, 0);
    driveAndTurn(-2, 0);
    driveAndTurn(1, 0);
    
}
void far(){

}