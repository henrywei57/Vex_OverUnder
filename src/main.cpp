#include "vex.h"
#include "botcontrol.h"
#include "basic_control.h"
#include "robot-config.h"
#include "main.h"
#include "autons/auton.h"
#include "autons/auton_functions.h"
#include "wing.h"
using namespace vex;
using namespace auton;
competition Competition;

int originX = 0;
int width = 240;
  
bool intawing = 0;
      
// int conlef = con.Axis1.position()+con.Axis3.position();

int endX = originX + width;

int autonoption = 0;
    float deadband(float input, float width){
  if (fabs(input)<width){
    return(0);
  }
  return(input);
}

void pre_auton(void) {
  vexcodeInit();
  bob.startCalibration();
  while(bob.isCalibrating()){
    wait(10, msec);
  }
  heading_convert(bob.heading());
}

void autonomous(void) {
  con.rumble("- .-. -..-. .");
close_qua();
far_qua();
  Brain.Screen.clearScreen();
  Brain.Screen.setFillColor(red);
  Brain.Screen.printAt(((480/2)-36), (240/2), "Auton Start!");
  // if(autonoption == 2){
  //   far();
  // } else if(autonoption == 1){

  // }
}

void usercontrol(void) {
    con.ButtonL2.pressed(Front_wings);
    con.ButtonL1.pressed(Back_wings);
  driver();

}
int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  pre_auton();
  while (true) {
    wait(100, msec);
  }
}