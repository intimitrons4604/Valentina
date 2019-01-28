#pragma once

#include <memory>

#include <frc/TimedRobot.h>
#include <frc/commands/Command.h>
#include <frc/smartdashboard/SendableChooser.h>

#include "Controls.h"
#include "commands/DriveCommand.h"
#include "subsystems/DriveTrain.h"
class Robot : public frc::TimedRobot
{
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;

 private:
  std::shared_ptr<Controls> controls;
  std::shared_ptr<DriveTrain> drivetrain;
  std::unique_ptr<DriveCommand> drivecommand;
};
