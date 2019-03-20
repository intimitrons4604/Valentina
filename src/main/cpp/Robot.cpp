#include "Robot.h"

#include <cameraserver/CameraServer.h>

#include <frc/commands/Scheduler.h>
#include <frc/smartdashboard/SmartDashboard.h>

void Robot::RobotInit()
{
  controls = std::make_shared<Controls>();
  drivetrain = std::make_shared<DriveTrain>();
  drivecommand = std::make_unique<DriveCommand>(controls, drivetrain);
  lift = std::make_shared<Lift>();
  liftcommand = std::make_unique<LiftCommand>(controls, lift);
  claw = std::make_shared<Claw>();
  clawcommand = std::make_unique<ClawCommand>(controls, claw);

  drivetrain->SetDefaultCommand(drivecommand.get());
  lift->SetDefaultCommand(liftcommand.get());
  claw->SetDefaultCommand(clawcommand.get());

  // camera stuff
  frc::CameraServer::GetInstance()->StartAutomaticCapture(0);
  frc::CameraServer::GetInstance()->StartAutomaticCapture(1);
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic()
{
}

/**
 * This function is called once each time the robot enters Disabled mode. You
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.
 */
void Robot::DisabledInit()
{
}

void Robot::DisabledPeriodic()
{
  frc::Scheduler::GetInstance()->Run();
}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString code to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional commands to the
 * chooser code above (like the commented example) or additional comparisons to
 * the if-else structure below with additional strings & commands.
 */
void Robot::AutonomousInit()
{
}

void Robot::AutonomousPeriodic()
{
  frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit()
{
}

void Robot::TeleopPeriodic()
{
  frc::Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic()
{
}

#ifndef RUNNING_FRC_TESTS
int main()
{
  return frc::StartRobot<Robot>();
}
#endif
