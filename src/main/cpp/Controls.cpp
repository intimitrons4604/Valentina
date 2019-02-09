#include "Controls.h"

#include <cmath>

using JoystickHand = frc::GenericHID::JoystickHand;
static constexpr double kDeadband = 0.02;
// TODO add adjust in tank and curvature drive if we were ever to use them
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
  arcadecontrols.xSpeed = adjust(controller1.GetY(JoystickHand::kLeftHand));
  arcadecontrols.zRotation = adjust(controller1.GetX(JoystickHand::kRightHand));

  return arcadecontrols;
}

double Controls::deadband(double controller, double deadband)
{
  if (std::abs(controller) < deadband)
  {
    return (0);
  }

  if (controller < 0)
  {
    return -((std::abs(controller) - deadband) / (1 - deadband));
  }
  return ((std::abs(controller) - deadband) / (1 - deadband));
}

double Controls::cubecontrols(double controller)
{
  return std::pow(controller, 3);
}
double Controls::adjust(double controller)
{
  double value = deadband(controller, kDeadband);
  return cubecontrols(value);
}

LiftControls Controls::Get_LiftControls()
{
  bool up = controller1.GetYButton();
  bool down = controller1.GetAButton();

  if (up && down)
  {
    return LiftControls::Stop;
  }
  else if (up)
  {
    return LiftControls::Up;
  }
  else if (down)
  {
    return LiftControls::Down;
  }
  else
  {
    return LiftControls::Stop;
  }
}
