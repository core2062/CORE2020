#include "PathFinder.h"
#include "Robot.h"

PathFinderAction::PathFinderAction() {
    // m_path = path;
}

void PathFinderAction::ActionInit() {

}

CORE::COREAutonAction::actionStatus PathFinderAction::Action() {
    Robot::GetInstance()->m_driveSubsystem.auton();
    m_autonomousCommand = Robot::GetInstance()->m_container.GetAutonomousCommand();
    if (m_autonomousCommand != nullptr) {
        m_autonomousCommand->Schedule();
    }
    return COREAutonAction::actionStatus::END;
}

void PathFinderAction::ActionEnd() {

}
