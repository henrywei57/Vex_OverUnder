#include "robot-config.h"
#include "autons/auton.h"
#include "main.h"
#include "autons/auton_functions.h"
using namespace vex;
using namespace auton;

void close_qua(){
    sped = 0.05;
    setHeading(0);
    suk(100);
    driveAndTurn(-1.72, 23, 100, 100);
    turnToAngle(0);
    driveAndTurn(0.05, 15, 100, 100);
    turnToAngle(90);
    inta.stop(hold);
    intawing2.set(1);
    unsuk(100);
    driveAndTurn(-1.15, 90, 100, 100);
    intawing2.set(0);
    driveAndTurn(0.2, 90, 100, 100);
    turnToAngle(45);
    driveAndTurn(2.47, 50, 100, 100);
    turnToAngle(-30);
    driveAndTurn(0.6, -85, 97, 100);
    sped = 0.1;
    driveAndTurn(1.3, -90, 100, 100);

}
void far_qua(){
    suk(30);
    wait(300, msec);
    driveAndTurn(1.3, 0);
    driveAndTurn(1, -90, 100, 70);
    driveAndTurn(-0.3, -90);
    turnToAngle(90);
    driveAndTurn(0.3, 90);
    unsuk(100);
}