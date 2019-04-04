#include "commands/DriveCommand.h"

DriveCommand::DriveCommand(std::shared_ptr<Controls> controls,
                           std::shared_ptr<DriveTrain> drivetrain)
    : controls(controls), drivetrain(drivetrain)
{
  Requires(drivetrain.get());
}

void DriveCommand::Initialize()
{
}

void DriveCommand::Execute()
{
  auto control = controls->Get_ArcadeDrive();
  drivetrain->ArcadeDrive(control.xSpeed, control.zRotation, control.turbo);
}

bool DriveCommand::IsFinished()
{
  return false;
}

void DriveCommand::End()
{
  drivetrain->Stop();
}

void DriveCommand::Interrupted()
{
  End();
}