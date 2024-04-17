#include "vex.h"
#include "botcontrol.h"
#include "basic_control.h"
#include "robot-config.h"
#include "main.h"
#include "autons/auton.h"
#include "autons/auton_functions.h"
#include "wing.h"
#include "utility/buttons.h"
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
  board();

  bob.startCalibration();
  while(bob.isCalibrating()){
    wait(10, msec);
  }
  // heading_convert(bob.heading());
  while(1){
  if (Brain.Screen.pressing()){
    int X = Brain.Screen.xPosition();
    int Y = Brain.Screen.yPosition();
    if ((Y <= 120) && (X >= 240)){
    Brain.Screen.drawRectangle(240, 30, 240, 105);
    Brain.Screen.setFillColor(green);
    Brain.Screen.setPenColor(black);
    Brain.Screen.printAt(315, 95, "Close Elim");
      autonoption = 1;

    } else if((Y <= 120) && (X <= 240)){
    Brain.Screen.drawRectangle(0, 30, 240, 105);
    Brain.Screen.setFillColor(green);
    Brain.Screen.setPenColor(black);
    Brain.Screen.printAt(85, 95, "Far Elim");  
      autonoption = 2;

    } else if((Y >= 120) && (X <= 240)){
    Brain.Screen.drawRectangle(0, 135, 240, 105);
    Brain.Screen.setFillColor(green);
    Brain.Screen.setPenColor(black);
    Brain.Screen.printAt(80, 195, "Far Qua");  
      autonoption = 3;

    } else if((Y >= 120) && (X >= 240)){
    Brain.Screen.drawRectangle(240, 135, 240, 105);
        Brain.Screen.setFillColor(green);
    Brain.Screen.setPenColor(black);
    Brain.Screen.printAt(310, 195, "Close Qua");  
      autonoption = 4;

    }
  }
  wait(20, msec);
}

//   vexcodeInit();
//   leftmo.setStopping(brake);
//   rightmo.setStopping(brake);
//   Brain.Screen.drawRectangle(240, 0, 240, 240, blue);
//   Brain.Screen.drawRectangle(0, 0, 240, 240, red);
//   Brain.Screen.setPenColor(white);
//   Brain.Screen.setPenWidth(5);
//   Brain.Screen.drawLine(240,0,240,240);
//   Brain.Screen.drawLine(0, 120, 480, 120);
//   Brain.Screen.drawLine(0, 0, 0, 240);
//   Brain.Screen.drawLine(0, 0, 480, 0);
//   Brain.Screen.drawLine(480, 240, 480, 0);
//   Brain.Screen.drawLine(480, 240, 0, 280);

//   Brain.Screen.printAt(480/2-54, 240/2/2+10, "Close Auton");
//   Brain.Screen.printAt(480/2-39, 240/2/2+10+120, "Far Auton");
//     // Brain.Screen.printAt(60, 60, "Far Auton");
//   bob.startCalibration();
//   while(bob.isCalibrating()){
//     wait(10, msec);
//   }
//   while(1){
//   if (Brain.Screen.pressing()){
//     int X = Brain.Screen.xPosition();
//     int Y = Brain.Screen.xPosition();
//     if ((Y >= 120)){
//       Brain.Screen.clearScreen();
//       Brain.Screen.drawRectangle(0,0,480,272);
//       Brain.Screen.setFillColor(red);
//       Brain.Screen.printAt(180,136, "Close Auton");
//       autonoption = 1;

//     } else if(Y <= 120){
//       Brain.Screen.clearScreen();
//       Brain.Screen.drawRectangle(0,0,480,272);
//       Brain.Screen.setFillColor(red);
//       Brain.Screen.printAt(190,136, "Far Auton");
//       autonoption = 2;
//     }
//   }
// }
}

void autonomous(void) {
  con.rumble("- .-. -----...-.-.-..-...----.-.-...--...-. .");
// close_qua();
// far_qua();
// close_elim();
  Brain.Screen.clearScreen();
  Brain.Screen.setFillColor(red);
  Brain.Screen.printAt(((480/2)-36), (240/2), "Auton Start!");
  if(autonoption == 1){
    close_elim();
  } else if(autonoption == 2){
    far_elim();
  } else if(autonoption == 3){
    far_qua();
  } else if(autonoption == 4){
    close_qua();
  }
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