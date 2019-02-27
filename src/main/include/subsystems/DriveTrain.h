#pragma once

#include "Wiring.h"
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
  frc::Talon left_front{PWM::left_front};
  frc::Talon left_back{PWM::left_back};
  frc::SpeedControllerGroup left_motors{left_front, left_back};

  frc::Talon right_front{PWM::right_front};
  frc::Talon right_back{PWM::right_back};
  frc::SpeedControllerGroup right_motors{right_front, right_back};

  frc::DifferentialDrive drive_motors{left_motors, right_motors};
};
