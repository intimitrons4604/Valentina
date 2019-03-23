#include "subsystems/DriveTrain.h"
static constexpr double kSpeedLimit = 0.5;
static const char* kSubSystemName = "DriveTrain";

DriveTrain::DriveTrain() : frc::Subsystem(kSubSystemName)
{
  drive_motors.SetDeadband(0);

  left_front.SetName(kSubSystemName, "LeftFrontMotor");
  left_back.SetName(kSubSystemName, "LeftBackMotor");
  left_motors.SetName(kSubSystemName, "LeftMotors");
  right_front.SetName(kSubSystemName, "RightFrontMotor");
  right_back.SetName(kSubSystemName, "RightBackMotor");
  right_motors.SetName(kSubSystemName, "RightMotors");
  drive_motors.SetName(kSubSystemName, "DriveMotors");
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