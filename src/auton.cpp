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
    timer tmer;
    sped = 0.065;
    setHeading(0);
    suk(100);
    driveAndTurn(-2.5, 0);
    turnToAngle(130);
    intawing1.set(1);
    intawing2.set(1);
    unsuk(100);
    sped = 0.1;
    driveAndTurn(-1.535, 123);
    sped = 0.05;
    intawing1.set(0);
    intawing2.set(0);
    turnToAngle(-93);
    suk(100);
    driveAndTurn(-1.26, -63, 100, 60);
    // driveAndTurn(0.1, -60, 100, 80);
    turnToAngle(-10);
    driveAndTurn(1.9867, -10, 100, 100);
    turnToAngle(-80);
    dropdown.set(1);
    driveAndTurn(0.6, -140, 100, 10);
    dropdown.set(0);
    turnToAngle(50);
    intawing1.set(1);
    wait(300, msec);
    unsuk(100);
    sped = 0.1;
    driveAndTurn(-0.9, 55, 100, 100);
    // driveAndTurn(0.5, -45, 100, 100);
    printf("%d",tmer.time(seconds));
}