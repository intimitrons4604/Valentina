#pragma once

#include <frc/XboxController.h>

#include "Wiring.h"

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

enum class LiftControls
{
  Stop,
  Down,
  Up
};

enum class ClawControls
{
  Open,
  Close,
  PinchBall,
  GetPanel,
  Stop
};

class Controls
{
 public:
  TankControls Get_TankDrive();
  CurvatureControls Get_CurvatureDrive();
  ArcadeControls Get_ArcadeDrive();
  LiftControls Get_LiftControls();
  ClawControls Get_ClawControls();

 private:
  frc::XboxController controller1{controller::main_controller};
  double deadband(double controller, double deadband);
  double cubecontrols(double controller);
  double adjust(double controller);
};