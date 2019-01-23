#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/Talon.h>

class drivetrain : public frc::Subsystem {  
    public:


    void tankdrive(double forwardbackward, double rightleft);

    

    private:
    frc::Talon left_motor1;
    frc::Talon left_motor2;
    frc::Talon right_motor1;
    frc::Talon right_motor2;


};

