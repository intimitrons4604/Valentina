#pragma once
#include <memory>
#include <frc/commands/Command.h>

#include "Controls.h"
#include "subsystems/Claw.h"

class ClawCommand : public frc::Command
{
 public:
  ClawCommand(std::shared_ptr<Controls> controls, std::shared_ptr<Claw> claw);

  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;

  private:
  std::shared_ptr<Controls> controls;
  std::shared_ptr<Claw> claw;
};