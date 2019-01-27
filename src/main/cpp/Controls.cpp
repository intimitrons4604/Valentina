#include "Controls.h"

using JoystickHand = frc::GenericHID::JoystickHand;

TankControls Controls::Get_TankDrive()
{
    TankControls tankcontrols;
    tankcontrols.leftSpeed = controller1.GetY(JoystickHand::kLeftHand);
    tankcontrols.rightSpeed = controller1.GetY(JoystickHand::kRightHand);
    
    return tankcontrols;

}

CurvatureControls Controls::Get_CurvatureDrive()
{
    CurvatureControls curvaturecontrols;
    curvaturecontrols.xSpeed = controller1.GetY(JoystickHand::kLeftHand);
    curvaturecontrols.zRotation = controller1.GetX(JoystickHand::kRightHand);
    curvaturecontrols.isQuickTurn = controller1.GetBumper(JoystickHand::kLeftHand);

    return curvaturecontrols;


}



ArcadeControls Controls::Get_ArcadeDrive()
{
    ArcadeControls arcadecontrols;
    arcadecontrols.xSpeed = controller1.GetY(JoystickHand::kLeftHand);
    arcadecontrols.zRotation = controller1.GetX(JoystickHand::kRightHand);

    return arcadecontrols;
}