#include "subsystems/Claw.h"

static constexpr double k_shaft_speed = 0.32;
static constexpr double k_finger_speed = 0.32;
static const char* kSubsystemName = "Claw";

Claw::Claw() : frc::Subsystem(kSubsystemName)
{
  finger_motor1.SetName(kSubsystemName, "FingerMotor1");
  finger_motor2.SetName(kSubsystemName, "FingerMotor2");
  finger_motor3.SetName(kSubsystemName, "FingerMotor3");
  finger_group.SetName(kSubsystemName, "FingerGroup");
  shaft_motor.SetName(kSubsystemName, "ShaftMotor");
  open_switch.SetName(kSubsystemName, "OpenSwitch");
  close_switch.SetName(kSubsystemName, "CloseSwitch");
}

void Claw::Open()
{
  if (open_switch.Get())
  {
    shaft_motor.StopMotor();
  }
  else
  {
    shaft_motor.Set(k_shaft_speed);
  }
}

void Claw::Close()
{
  if (close_switch.Get())
  {
    shaft_motor.StopMotor();
  }
  else
  {
    shaft_motor.Set(-k_shaft_speed);
  }
}

void Claw::StopShaft()
{
  shaft_motor.StopMotor();
}

void Claw::Suck()
{
  finger_group.Set(k_finger_speed);
}

void Claw::Expel()
{
  finger_group.Set(-k_finger_speed);
}

void Claw::StopFingers()
{
  finger_group.StopMotor();
}