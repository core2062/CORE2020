
#pragma once

#include <frc/controller/PIDController.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc2/command/Command.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/PIDCommand.h>
#include <frc2/command/ParallelRaceGroup.h>
#include <frc2/command/RunCommand.h>

#include "Constants.h"
#include "DriveSubsystem.h"
#include "CORERobotLib.h"

using namespace CORE;

class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();
  frc2::Command* GetTeleopDriveCommand();

 private:

  // The robot's subsystems and commands are defined here...

  // The robot's subsystems
  DriveSubsystem m_drive;

  // The chooser for the autonomous routines
  frc::SendableChooser<frc2::Command*> m_chooser;
};
