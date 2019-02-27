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

}

namespace DIO
{
    // For lift limit switches
    constexpr int down_liftswitch = 7;
    constexpr int up_liftswitch = 8;
}

namespace controller
{
    constexpr int main_controller = 0;
}

