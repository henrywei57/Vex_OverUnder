#pragma once
namespace auton {
    extern double sped;
    void driveAndTurn(double tiles, double angle, double linearMaxVelocity = 100, double turnMaxVelocity = 100, double timeoutMs = 1500);
    void turnToAngle(double angle, double MaxVelocity = 100, double timeoutMs = 1500);
    void driveVelocity(double leftPct, double rightPct);
}