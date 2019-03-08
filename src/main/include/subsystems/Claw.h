#pragma once

#include "Wiring.h"
#include <frc/Talon.h>
#include <frc/DigitalInput.h>
#include <frc/commands/Subsystem.h>


class Claw : public frc::Subsystem
{
    public:
    void Open();
    void Close();
    void Pinch();
    void IntoHatch();


    private:
    frc::Talon finger_motor1{PWM::finger_motor1};
    frc::Talon finger_motor2{PWM::finger_motor2};
    frc::Talon finger_motor3{PWM::finger_motor3};
    frc::Talon shaft_motor{PWM::shaft_motor};

    frc::DigitalInput open_switch{DIO::open_clawswitch};
    frc::DigitalInput close_switch{DIO::close_clawswitch};
    
};