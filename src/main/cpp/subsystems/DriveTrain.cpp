#include "subsystems/DriveTrain.h"
static constexpr double kSpeedLimit = 0.5;
DriveTrain::DriveTrain() : frc::Subsystem("DriveTrain")
{
  drive_motors.SetDeadband(0);
  left_motors.SetInverted(true);
  right_motors.SetInverted(true);
}

void DriveTrain::TankDrive(double leftSpeed, double rightSpeed)
{
  double leftSpeedLimit = leftSpeed * kSpeedLimit;
  double rightSpeedLimit = rightSpeed * kSpeedLimit;
  drive_motors.TankDrive(leftSpeedLimit, rightSpeedLimit, false);
}

void DriveTrain::CurvatureDrive(double xSpeed, double zRotation, bool isQuickTurn)
{
  double xSpeedLimit = xSpeed * kSpeedLimit;
  double zSpeedLimit = zRotation * kSpeedLimit;
  drive_motors.CurvatureDrive(xSpeedLimit, zSpeedLimit, isQuickTurn);
}

void DriveTrain::ArcadeDrive(double xSpeed, double zRotation)
{
  double xSpeedLimit = xSpeed * kSpeedLimit;
  double zSpeedLimit = zRotation * kSpeedLimit;
  drive_motors.ArcadeDrive(xSpeedLimit, zSpeedLimit, false);
}

void DriveTrain::Stop()
{
  drive_motors.StopMotor();
}