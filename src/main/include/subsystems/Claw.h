#pragma once

#include <frc/Counter.h>
#include <frc/DigitalInput.h>
#include <frc/Encoder.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/Talon.h>
#include <frc/commands/Subsystem.h>

#include "Wiring.h"

class Claw : public frc::Subsystem
{
 public:
  Claw();

  void Open();
  void Close();
  void StopShaft();

  void Suck();
  void Expel();
  void StopFingers();

 private:
  frc::Talon finger_motor1{PWM::finger_motor1};
  frc::Talon finger_motor2{PWM::finger_motor2};
  frc::Talon finger_motor3{PWM::finger_motor3};
  frc::SpeedControllerGroup finger_group{finger_motor1, finger_motor2, finger_motor3};

  frc::Talon shaft_motor{PWM::shaft_motor};

  frc::DigitalInput open_switch{DIO::open_clawswitch};
  frc::DigitalInput close_switch{DIO::close_clawswitch};

  frc::Encoder encoder{DIO::encoderA, DIO::encoderB};
  frc::Counter indexchannel{DIO::indexchannel};
};