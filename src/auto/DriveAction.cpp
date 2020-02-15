#include "DriveAction.h"

DriveAction::DriveAction(driveAction requestedDriveAction) {
    m_driveAction = requestedDriveAction;

}

void DriveAction::ActionInit() {

}

CORE::COREAutonAction::actionStatus DriveAction::Action() {
    switch(m_driveAction) {
        case FORWARD:
            Robot::GetInstance()->driveSubsystem.setMotorSpeed(0.5, DriveSide::BOTH);
            break;
        case BACKWARD:
            Robot::GetInstance()->driveSubsystem.setMotorSpeed(-0.5, DriveSide::BOTH);
            break;
    }
    return COREAutonAction::actionStatus::END;
}

void DriveAction::ActionEnd() {

}