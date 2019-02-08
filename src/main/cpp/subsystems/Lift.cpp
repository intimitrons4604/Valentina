#include "subsystems/Lift.h"
static constexpr double kSpeed = 0.5;

void Lift::Up()
{
  if (up_switch.Get())
  {
    victors.StopMotor();
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
    victors.StopMotor();
  }
  victors.Set(-kSpeed);
}
