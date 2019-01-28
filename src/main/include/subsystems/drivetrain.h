#pragma once

#include <frc/SpeedControllerGroup.h>
#include <frc/Talon.h>
#include <frc/commands/Subsystem.h>
#include <frc/drive/DifferentialDrive.h>

class DriveTrain : public frc::Subsystem
{
 public:
  DriveTrain();
  void TankDrive(double leftSpeed, double rightSpeed);

  void CurvatureDrive(double xSpeed, double zRotation, bool isQuickTurn);

  void ArcadeDrive(double xSpeed, double zRotation);

  void Stop();

 private:
  frc::Talon left_front{4};
  frc::Talon left_back{3};
  frc::SpeedControllerGroup left_motors{left_front, left_back};

  frc::Talon right_front{1};
  frc::Talon right_back{2};
  frc::SpeedControllerGroup right_motors{right_front, right_back};

  frc::DifferentialDrive drive_motors{left_motors, right_motors};
};
