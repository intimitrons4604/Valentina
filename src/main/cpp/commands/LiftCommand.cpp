#include "commands/LiftCommand.h"

LiftCommand::LiftCommand(std::shared_ptr<Controls> controls, std::shared_ptr<Lift> lift)
    : controls(controls), lift(lift)
{
  Requires(lift.get());
}

void LiftCommand::Initialize()
{
}

void LiftCommand::Execute()
{
  auto control = controls->Get_LiftControls();
  switch (control)
  {
    case LiftControls::Stop:
      lift->Stop();
      break;
    case LiftControls::Up:
      lift->Up();
      break;
    case LiftControls::Down:
      lift->Down();
      break;
    default:
      lift->Stop();
      break;
  }
}

bool LiftCommand::IsFinished()
{
  return false;
}

void LiftCommand::End()
{
  lift->Stop();
}

void LiftCommand::Interrupted()
{
  End();
}