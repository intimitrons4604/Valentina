#include "Controls.h"

#include <cmath>

using JoystickHand = frc::GenericHID::JoystickHand;
static constexpr double kDeadband = 0.02;
TankControls Controls::Get_TankDrive()
{
  TankControls tankcontrols;
  tankcontrols.leftSpeed = adjust(controller1.GetY(JoystickHand::kLeftHand) * -1);
  tankcontrols.rightSpeed = adjust(controller1.GetY(JoystickHand::kRightHand) * -1);

  return tankcontrols;
}

CurvatureControls Controls::Get_CurvatureDrive()
{
  CurvatureControls curvaturecontrols;
  curvaturecontrols.xSpeed = adjust(controller1.GetY(JoystickHand::kLeftHand) * -1);
  curvaturecontrols.zRotation = adjust(controller1.GetX(JoystickHand::kRightHand));
  curvaturecontrols.isQuickTurn = controller1.GetBumper(JoystickHand::kLeftHand);

  return curvaturecontrols;
}

ArcadeControls Controls::Get_ArcadeDrive()
{
  ArcadeControls arcadecontrols;
  arcadecontrols.xSpeed = adjust(controller1.GetY(JoystickHand::kLeftHand) * -1);
  arcadecontrols.zRotation = adjust(controller1.GetX(JoystickHand::kRightHand));
  arcadecontrols.turbo = controller1.GetTriggerAxis(JoystickHand::kRightHand) >= 0.8;

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

ClawControls Controls::Get_ClawControls()
{
  bool close = controller1.GetBumper(JoystickHand::kLeftHand);
  bool open = controller1.GetBumper(JoystickHand::kRightHand);

  if (open && close)
  {
    return ClawControls::Stop;
  }
  else if (open)
  {
    return ClawControls::Open;
  }
  else if (close)
  {
    return ClawControls::Close;
  }
  else
  {
    return ClawControls::Stop;
  }
}
