#include "robot-config.h"
#include "autons/auton.h"
#include "main.h"
#include "autons/auton_functions.h"
using namespace vex;
using namespace auton;

void close_qua(){
    it.setHeading(0, degrees);
    inta.spin(reverse, 100, pct);
    driveAndTurn(-1.9, 15, 100, 100);
    turnToAngle(90);
    inta.spin(fwd, 100, pct);
    driveAndTurn(-1.2, 90, 100, 100);
    driveAndTurn(0.15, 80, 100, 100);
    turnToAngle(45);
    driveAndTurn(2.55, 45, 100, 100);
    turnToAngle(-30);
    driveAndTurn(0.9, -85, 97, 100);
    driveAndTurn(1.45, -90, 100, 100);
}
void far_qua(){

}