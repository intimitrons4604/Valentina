#pragma once

#include <frc/XboxController.h>

struct TankControls
{
    double leftSpeed;
    double rightSpeed;
};

struct CurvatureControls
{
    double xSpeed;
    double zRotation;
    bool isQuickTurn;
};

struct ArcadeControls
{

    double xSpeed;
    double zRotation;
};

class Controls
{

  public:
    TankControls Get_TankDrive();
    CurvatureControls Get_CurvatureDrive();
    ArcadeControls Get_ArcadeDrive();

  private:
    frc::XboxController controller1{0};
};