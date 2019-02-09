#pragma once
#include <memory>

#include <frc/commands/Command.h>

#include "Controls.h"
#include "subsystems/Lift.h"

class LiftCommand : public frc::Command
{
 public:
  LiftCommand(std::shared_ptr<Controls> controls, std::shared_ptr<Lift> lift);

  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;

 private:
  std::shared_ptr<Controls> controls;
  std::shared_ptr<Lift> lift;
};