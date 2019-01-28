#include "subsystems/DriveTrain.h"

DriveTrain::DriveTrain() : frc::Subsystem("DriveTrain")
{
  drive_motors.SetDeadband(0);
}

void DriveTrain::TankDrive(double leftSpeed, double rightSpeed)
{
  drive_motors.TankDrive(leftSpeed, rightSpeed, false);
}

void DriveTrain::CurvatureDrive(double xSpeed, double zRotation, bool isQuickTurn)
{
  drive_motors.CurvatureDrive(xSpeed, zRotation, isQuickTurn);
}

void DriveTrain::ArcadeDrive(double xSpeed, double zRotation)
{
  drive_motors.ArcadeDrive(xSpeed, zRotation, false);
}

void DriveTrain::Stop()
{
  drive_motors.StopMotor();
}