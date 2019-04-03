#pragma once

//Change Talon back to Victor when appropriate
#include "Wiring.h"
#include <frc/DigitalInput.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/Talon.h>
#include <frc/commands/Subsystem.h>

class Lift : public frc::Subsystem
{
 public:
  void Up();
  void Down();
  void Stop();
  Lift();

 private:
  frc::Talon left_victor{PWM::left_liftmotor};
  frc::Talon right_victor{PWM::right_liftmotor};
  frc::SpeedControllerGroup victors{left_victor, right_victor};
  // These limit switches are normally closed
  frc::DigitalInput down_switch{DIO::down_liftswitch};
  frc::DigitalInput up_switch{DIO::up_liftswitch};
};