#include "PathFinder.h"
#include "Robot.h"

PathFinderAction::PathFinderAction(std::string path) {
    m_path = path;
}

void PathFinderAction::ActionInit() {

}

CORE::COREAutonAction::actionStatus PathFinderAction::Action() {
    Robot::GetInstance()->m_driveSubsystem.auton();
    m_autonomousCommand = Robot::GetInstance()->m_container.GetAutonomousCommand(m_path);
    if (m_autonomousCommand != nullptr) {
        m_autonomousCommand->Schedule();
    }
    cout << "running path finder action" << endl;
    return COREAutonAction::actionStatus::END;
}

void PathFinderAction::ActionEnd() {

}
