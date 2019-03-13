#include "commands/ClawCommand.h"

ClawCommand::ClawCommand(std::shared_ptr<Controls> controls, std::shared_ptr<Claw> claw)
    : controls(controls), claw(claw)
{
  Requires(claw.get());
}

void ClawCommand::Initialize()
{
}

void ClawCommand::Execute()
{
  auto control = controls->Get_ClawControls();
  switch (control)
  {
    case ClawControls::Stop:
      claw->StopShaft();
      claw->StopFingers();
      break;
    case ClawControls::Open:
      claw->Open();
      claw->Expel();
      break;
    case ClawControls::Close:
      claw->Close();
      claw->Suck();
      break;
    default:
      claw->StopShaft();
      claw->StopFingers();
      break;
  }
}

bool ClawCommand::IsFinished()
{
  return false;
}

void ClawCommand::End()
{
  claw->StopFingers();
  claw->StopShaft();
}

void ClawCommand::Interrupted()
{
  End();
}