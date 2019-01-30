#pragma once
#include <memory>

#include <frc/commands/Command.h>

#include "Controls.h"
#include "subsystems/DriveTrain.h"

class DriveCommand : public frc::Command
{
 public:
  DriveCommand(std::shared_ptr<Controls> controls, std::shared_ptr<DriveTrain> drivetrain);

  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;

 private:
  std::shared_ptr<Controls> controls;
  std::shared_ptr<DriveTrain> drivetrain;
};