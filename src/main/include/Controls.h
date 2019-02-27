#pragma once

#include "Wiring.h"
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

enum class LiftControls
{
  Stop, Down, Up
};

class Controls
{
 public:
  TankControls Get_TankDrive();
  CurvatureControls Get_CurvatureDrive();
  ArcadeControls Get_ArcadeDrive();
  LiftControls Get_LiftControls();


 private:
  frc::XboxController controller1{controller::main_controller};
  double deadband(double controller, double deadband);
  double cubecontrols(double controller);
  double adjust(double controller);
};