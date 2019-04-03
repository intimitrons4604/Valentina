#include "subsystems/Lift.h"

//original speed is 0.5, but no limit switches are currently connected. Test speed is 0.1, possibly 0.2
static constexpr double kSpeed = 0.1;
static const char* kSubsystemName = "Lift";



Lift ::Lift() : frc::Subsystem(kSubsystemName)
{
  right_victor.SetInverted(true);
  left_victor.SetName(kSubsystemName, "LeftLiftMotor");
  right_victor.SetName(kSubsystemName, "RightLiftMotor");
  victors.SetName(kSubsystemName, "LiftMotorGroup");
  down_switch.SetName(kSubsystemName, "DownLiftSwitch");
  up_switch.SetName(kSubsystemName, "UpLiftSwitch");
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