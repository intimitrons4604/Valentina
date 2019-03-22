#pragma once

namespace PWM
{
    // For drive motors
    constexpr int left_front = 4;
    constexpr int left_back = 3;
    constexpr int right_front = 1;
    constexpr int right_back = 2;
    // For lift motors
    constexpr int left_liftmotor = 5;
    constexpr int right_liftmotor = 6;
    // For claw motors
    constexpr int finger_motor1 = 0;
    constexpr int finger_motor2 = 7;
    constexpr int finger_motor3 = 8;
    constexpr int shaft_motor = 9;

}

namespace DIO
{
    // For lift limit switches
    constexpr int down_liftswitch = 7;
    constexpr int up_liftswitch = 8;
    // For claw limit switches
    constexpr int open_clawswitch = 0;
    constexpr int close_clawswitch = 1;
    // For encoder
    constexpr int encoderA = 2;
    constexpr int encoderB = 3;
    constexpr int indexchannel = 3;
}

namespace controller
{
    constexpr int main_controller = 0;
}

