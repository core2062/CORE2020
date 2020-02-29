#include <Robot.h>

Robot * Robot::m_instance;

Robot::Robot() {
	m_instance = this;
}

void Robot::robotInit() {
	wpi::SmallString<64> deployDirectory;
    frc::filesystem::GetDeployDirectory(deployDirectory);
    wpi::sys::path::append(deployDirectory, "paths");
    wpi::sys::path::append(deployDirectory, "example.wpilib.json");
    frc::Trajectory trajectory = frc::TrajectoryUtil::FromPathweaverJson(deployDirectory);

}

void Robot::RobotPeriodic() {
    frc2::CommandScheduler::GetInstance().Run();
}

void Robot::TeleopPeriodic() {
    std::cout << "running teleop periodic" << endl;
    m_driveSubsystem.teleop();
}

void Robot::teleopInit() {
    
}

void Robot::test() {

}

void Robot::teleop() {
    std::cout << "running teleop" << endl;
    m_driveSubsystem.teleop();
}

void Robot::testInit() {
  
}

Robot * Robot::GetInstance() {
	return m_instance;
}

#ifndef RUNNING_FRC_TESTS
int main() { 
	return frc::StartRobot<Robot>(); 
}
#endif