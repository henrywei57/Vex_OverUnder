#include "vex.h"
#include "botcontrol.h"
#include "basic_control.h"
#include "robot-config.h"
#include "main.h"
#include "autons/auton.h"
#include "utility/buttons.h"
using namespace vex;
competition Competition;

int originX = 0;
int width = 240;
  
bool intawing = 0;
      
// int conlef = con.Axis1.position()+con.Axis3.position();

int endX = originX + width;

    float deadband(float input, float width){
  if (fabs(input)<width){
    return(0);
  }
  return(input);
}

void pre_auton(void) {
  vexcodeInit();
  leftmo.setStopping(brake);
  rightmo.setStopping(brake);
  Brain.Screen.drawRectangle(240, 0, 240, 240, blue);
  Brain.Screen.drawRectangle(0, 0, 240, 240, red);
  Brain.Screen.setPenColor(white);
  Brain.Screen.setPenWidth(5);
  Brain.Screen.drawLine(240,0,240,240);
  Brain.Screen.drawLine(0, 120, 480, 120);
  Brain.Screen.drawLine(0, 0, 0, 240);
  Brain.Screen.drawLine(0, 0, 480, 0);
  Brain.Screen.drawLine(480, 240, 480, 0);
  Brain.Screen.drawLine(480, 240, 0, 280);

  Brain.Screen.printAt(480/2-54, 240/2/2+10, "Close Auton");
  Brain.Screen.printAt(480/2-39, 240/2/2+10+120, "Far Auton");
    // Brain.Screen.printAt(60, 60, "Far Auton");
  it.startCalibration();
  while(it.isCalibrating()){
    wait(10, msec);
  }

}

void autonomous(void) {
  con.rumble("- .-. -..-. .");
  test();
  // Brain.Screen.printAt(((480/2)-36), (240/2), "Auton Start!");
  if(autonpick == 2){
    far();
  } else if(autonpick == 1){

  }
}

void usercontrol(void) {
timer tmer;
keybind();
  while (1) {
  if (con.ButtonL1.pressing()) {
            // If the wing is not deployed, deploy it
            if (!intawing) {
                intawings.set(true);
                intawing = true;
            } 
            // If the wing is deployed, retract it
            else {
                intawings.set(false);
                intawing = false;
            }

            // Wait for the button to be released
            while (con.ButtonL1.pressing()) {
                vex::task::sleep(20);
            }
        }
    if(tmer.time(seconds) == 75){
      con.rumble(".. .-");
    }
    if(con.ButtonR1.pressing()){
      inta.spin(reverse, 100, pct);
    } else if(con.ButtonR2.pressing()){
      inta.spin(fwd, 100, pct);
    } else{
      inta.stop(hold);
    }
    if(con.ButtonY.pressing()){
      pner.spin(fwd, 100, pct);
    } else{
          pner.stop(hold);
    }
    // Brain.Screen.print((leftmo.velocity(pct)+rightmo.velocity(pct))/2);
    // Brain.Screen.print(con.Axis1.position()+con.Axis3.position());
    leftmo.setStopping(brake);
    rightmo.setStopping(brake);

    // driver();
    // leftmo.spin(fwd,(con.Axis1.value()+con.Axis3.value())*12/100,voltageUnits::volt);
  //  rightmo.spin(fwd,(con.Axis3.value()-con.Axis1.value())*12/100,voltageUnits::volt);
      //  leftmo.stop();
    // rightmo.stop();
    float throttle = deadband(controller(primary).Axis3.value(), 5);
  float turn = deadband(controller(primary).Axis1.value(), 5);
  rightmo.spin(fwd, 12/100*(throttle+turn), volt);
  leftmo.spin(fwd, 12/100*(throttle-turn), volt);
  r3.spin(fwd, 12/100*(throttle+turn), volt);
  l3.spin(fwd, 12/100*(throttle-turn), volt);
    wait(20, msec);
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1,1);
  }

}
int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  pre_auton();
  while (true) {
    wait(100, msec);
  }
}