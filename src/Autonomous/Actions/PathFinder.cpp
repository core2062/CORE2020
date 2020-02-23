#include "PathFinder.h"
// #include <frc/Filesystem.h>
// #include <frc/trajectory/TrajectoryUtil.h>
// #include <frc/trajectory/Trajectory.h>
// #include <wpi/Path.h>
// #include <wpi/SmallString.h>

// wpi::SmallString<64> deployDirectory;
// frc::filesystem::GetDeployDirectory(deployDirectory);
// wpi::sys::path::append(deployDirectory, "paths");
// wpi::sys::path::append(deployDirectory, "YourPath.wpilib.json");

// frc::Trajectory trajectory = frc::TrajectoryUtil::FromPathweaverJson(deployDirectory);

void PathFinderAction::ActionInit() {

}

CORE::COREAutonAction::actionStatus PathFinderAction::Action() {

}

void PathFinderAction::ActionEnd() {

}

// frc2::Command* RobotContainer::GetAutonomousCommand() {
//   // Create a voltage constraint to ensure we don't accelerate too fast
//   frc::DifferentialDriveVoltageConstraint autoVoltageConstraint(
//       frc::SimpleMotorFeedforward<units::meters>(
//           DriveConstants::ks, DriveConstants::kv, DriveConstants::ka),
//       DriveConstants::kDriveKinematics, 10_V);

//   // Set up config for trajectory
//   frc::TrajectoryConfig config(AutoConstants::kMaxSpeed,
//                                AutoConstants::kMaxAcceleration);
//   // Add kinematics to ensure max speed is actually obeyed
//   config.SetKinematics(DriveConstants::kDriveKinematics);
//   // Apply the voltage constraint
//   config.AddConstraint(autoVoltageConstraint);

//   // An example trajectory to follow.  All units in meters.
//   auto exampleTrajectory = frc::TrajectoryGenerator::GenerateTrajectory(
//       // Start at the origin facing the +X direction
//       frc::Pose2d(0_m, 0_m, frc::Rotation2d(0_deg)),
//       // Pass through these two interior waypoints, making an 's' curve path
//       {frc::Translation2d(1_m, 1_m), frc::Translation2d(2_m, -1_m)},
//       // End 3 meters straight ahead of where we started, facing forward
//       frc::Pose2d(3_m, 0_m, frc::Rotation2d(0_deg)),
//       // Pass the config
//       config);

//   frc2::RamseteCommand ramseteCommand(
//       exampleTrajectory, [this]() { return m_drive.getPose(); },
//       frc::RamseteController(AutoConstants::kRamseteB,
//                              AutoConstants::kRamseteZeta),
//       frc::SimpleMotorFeedforward<units::meters>(
//           DriveConstants::ks, DriveConstants::kv, DriveConstants::ka),
//       DriveConstants::kDriveKinematics,
//       [this] { return m_drive.getWheelSpeeds(); },
//       frc2::PIDController(DriveConstants::kPDriveVel, 0, 0),
//       frc2::PIDController(DriveConstants::kPDriveVel, 0, 0),
//       [this](auto left, auto right) { m_drive.tankDriveVolts(left, right); },
//       {&m_drive});

//   // no auto
//   return new frc2::SequentialCommandGroup(
//       std::move(ramseteCommand),
//       frc2::InstantCommand([this] { m_drive.tankDriveVolts(0_V, 0_V); }, {}));
// }
