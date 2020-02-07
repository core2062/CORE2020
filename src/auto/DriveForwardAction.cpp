#include <Robot.h>
#include <DriveForwardAction.h>

DriveForwardAction::DriveForwardAction(driveForwardAction requestedDriveForwardAction) {
    m_driveForwardAction = requestedDriveForwardAction;

}

void DriveForwardAction::ActionInit() {

}

CORE::COREAutonAction::actionStatus DriveForwardAction::Action() {
    switch(m_driveForwardAction) {
        case FORWARD:
            Robot::GetInstance()->driveSubsystem.setMotorSpeed(0.5, DriveSide::BOTH);
            break;
        case BACKWARD:
            Robot::GetInstance()->driveSubsystem.setMotorSpeed(-0.5, DriveSide::BOTH);
            break;
        case STOP:
            Robot::GetInstance()->driveSubsystem.setMotorSpeed(0, DriveSide::BOTH);
            break;
    return COREAutonAction::actionStatus::END;
    }
}

void DriveForwardAction::ActionEnd() {

}