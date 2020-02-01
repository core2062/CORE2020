#include <frc/Filesystem.h>
#include <frc/trajectory/TrajectoryUtil.h>
#include <frc/trajectory/Trajectory.h>
#include <wpi/Path.h>
#include <wpi/SmallString.h>

wpi::SmallString<64> deployDirectory;
frc::filesystem::GetDeployDirectory(deployDirectory);
wpi::sys::path::append(deployDirectory, "paths");
wpi::sys::path::append(deployDirectory, "YourPath.wpilib.json");

frc::Trajectory trajectory = frc::TrajectoryUtil::FromPathweaverJson(deployDirectory);

