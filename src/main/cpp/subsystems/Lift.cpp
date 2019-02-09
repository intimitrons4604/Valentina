#include "subsystems/Lift.h"
static constexpr double kSpeed = 0.5;

Lift :: Lift() : frc::Subsystem("Lift")
{
}

void Lift::Up()
{
  if (up_switch.Get())
  {
    Stop();
  }
  else
  {
    victors.Set(kSpeed);
  }
}

void Lift::Down()
{
  if (down_switch.Get())
  {
    Stop();
  }
  else
  {
    victors.Set(-kSpeed);
  }
}

void Lift::Stop()
{
  victors.StopMotor();
}