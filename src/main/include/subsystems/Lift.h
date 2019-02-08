#pragma once

#include <frc/DigitalInput.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/Victor.h>
#include <frc/commands/Subsystem.h>

class Lift : public frc::Subsystem
{
 public:
  void Up();
  void Down();
  void Stop();

 private:
  frc::Victor left_victor{5};
  frc::Victor right_victor{6};
  frc::SpeedControllerGroup victors{left_victor, right_victor};
  // These limit switches are normally closed
  frc::DigitalInput down_switch{7};
  frc::DigitalInput up_switch{8};
};