#include "autons/auton_functions.h"
#include "utility/pid_control.h"
#include "robot-config.h"
#include "main.h"
#include "iostream"
double newTurnVelocity;
namespace auton {
    void motor_spin(double L_speed, double R_speed, velocityUnits units){
  leftmo.spin(fwd, L_speed, units);
  rightmo.spin(fwd, R_speed, units);
}
void motor_stop(brakeType mode){
  leftmo.stop(mode);
  rightmo.stop(mode);
}
double heading_convert(double heading){
  return(heading > 180) ? heading - 360 : heading;
  /*twenRY Operator A = (condition) ? (true data) : (false data)*/
}


    double sped = 0.0278;
    void driveAndTurn(double tiles, double angle, double linearMaxVelocity, double turnMaxVelocity, double timeoutMs){
        double distanceDegree = tiles * (24.0 / 1.0) * (1.0 / (M_PI * 3.5 )) * (84.0 / 1.0) * (1.0 / 48.0) * (360.0 / 1.0);
        double initLeftMoterDegree = leftmo.position(degrees);
        double initRightMoterDegree = rightmo.position(degrees);
        // PIDControl drivePID(sped, 0, 0, 2);
        PIDControl drivePID(0.03, 0, 0, 2);
        PIDControl rotateToPID(0.6, 0, 0, 2);
        timer timeout;
        while(timeout.time(msec) <= timeoutMs && (!drivePID.reachedGoal() || !rotateToPID.reachedGoal())) {
            // Get linear velocity
            double currentLeftMotorDegree = leftmo.position(degrees);
            double currentRightMotorDegree = rightmo.position(degrees);
            double leftTraveledDegree = currentLeftMotorDegree - initLeftMoterDegree;
            double rightTraveledDegree = currentRightMotorDegree - initRightMoterDegree;
            double averageTraveledDegree = (leftTraveledDegree+rightTraveledDegree)/2;
            double error = distanceDegree - averageTraveledDegree;
            drivePID.computeFromError(error);
            double newLinearVelocity = drivePID.getValue();
            newLinearVelocity = fmax(-linearMaxVelocity, fmin(linearMaxVelocity, newLinearVelocity));

            // Get turning velocity
            if(angle != 0){
                double rotateError = angle - it.rotation(deg);
                rotateToPID.computeFromError(rotateError);
                newTurnVelocity = rotateToPID.getValue();
                newTurnVelocity = fmax(-turnMaxVelocity, fmin(turnMaxVelocity, newTurnVelocity));
            } else{
                newTurnVelocity = 0;
            }
            // Get final velocity
            double finalLeftVelocity = newLinearVelocity + newTurnVelocity;
            double finalRightVelocity = newLinearVelocity - newTurnVelocity;
            // double finalLeftVelocity = newTurnVelocity - newLinearVelocity;
            // double finalRightVelocity = newLinearVelocity + newTurnVelocity;
            driveVelocity(finalLeftVelocity, finalRightVelocity);

            task::sleep(20);
        }
        leftmo.stop();
        rightmo.stop();
    }
    void turnToAngle(double angle, double MaxVelocity, double timeoutMs){
        PIDControl rotateToPID(3, 0.0005, 0, 2);
        // PIDControl rotateToPID();
        timer timeout;
        while(timeout.time(msec) <= timeoutMs && !rotateToPID.reachedGoal()){
            double error = -angle - it.rotation(degrees);
            rotateToPID.computeFromError(error);
            double newTurnVelocity = rotateToPID.getValue();
            driveVelocity(newTurnVelocity, -newTurnVelocity);
            printf("error%3f\n",error);
            task::sleep(20); 

        }
        leftmo.stop();
        rightmo.stop();
    }
    void driveVelocity(double leftPct, double rightPct){
        double scale = 100.0 / fmax(100.0, fmax(fabs(leftPct), fabs(rightPct)));
        leftPct *= scale;
        rightPct *= scale;
        leftmo.spin(fwd, leftPct, pct);
        rightmo.spin(fwd, rightPct, pct);
    }
void turn(float turn_degree){
  float speed_now = 0;

  float kp = 0.6;
  float ki = 0;
  float kd = 2;

  float error = 0;
  float prev_error = 0;
  float INT = 0;

  int counter = 0;

  timer timeout;
  
  while (counter < 5 && timeout.value() <= 3){

    error = turn_degree - it.heading();
    INT = INT + error;
    speed_now = error * kp + INT * ki + (error - prev_error) * kd;

    motor_spin(speed_now, -speed_now, rpm);

    prev_error = error;

    if (fabs(it.heading() - turn_degree) < 0.5){
      counter++;
    }
    else{
      counter = 0;
    }
    wait(10, msec);
  }
  motor_stop(brake);
}
}