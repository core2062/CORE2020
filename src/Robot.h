#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <CORERobotLib.h>
#include <frc2/command/CommandScheduler.h>
#include <DriveSubsystem.h>
#include <LauncherSubsystem.h>
#include <ClimberSubsystem.h>
#include <IntakeSubsystem.h>
#include <ConveyorSubsystem.h>
#include <COREFramework/COREScheduler.h>
#include <Autonomous/Auton.h>
#include <frc/trajectory/TrajectoryUtil.h>
#include <wpi/Path.h>
#include <frc2/command/Command.h>
#include <RobotContainer.h>
#include <wpi/SmallString.h>
#include <frc/Filesystem.h>
#include <iostream>

/* Drive ports */
#define LEFT_FRONT_PORT 11
#define LEFT_BACK_PORT 10
#define RIGHT_FRONT_PORT 12
#define RIGHT_BACK_PORT 13
#define INTAKE_PORT 14
#define CONVEYOR_1_PORT 15
#define CONVEYOR_2_PORT 16
#define TURRET_PORT 17


/* Solenoids */
#define LEFT_DRIVE_SHIFTER_PCM 1
#define RIGHT_DRIVE_SHIFTER_PCM 1
#define COMPRESSOR_PCM 2
#define LEFT_DRIVE_SHIFTER_HIGH_GEAR_PORT 0
#define RIGHT_DRIVE_SHIFTER_HIGH_GEAR_PORT 2 
#define LEFT_DRIVE_SHIFTER_LOW_GEAR_PORT 1
#define RIGHT_DRIVE_SHIFTER_LOW_GEAR_PORT 3
#define INTAKE_DOWN_PORT 4
#define INTAKE_UP_PORT 5


/* Launcher Ports */
#define TOP_LAUNCHER_MOTOR_PORT 15
#define BOTTOM_LAUNCHER_MOTOR_PORT 16

using namespace CORE;
using namespace std;

class Robot : public CORERobot {
public: 
 	Robot();
	void RobotPeriodic() override;
	void robotInit() override;
    void teleopInit() override;
    void teleop() override;
	void test() override;
	void testInit() override;
	static Robot * GetInstance();
	DriveSubsystem m_driveSubsystem;
	RobotContainer m_container;
	Autonomous driveAuto;
private:
  	frc2::Command* m_autonomousCommand = nullptr;
	static Robot * m_instance;
};