#include "DriveAction.h"

DriveAction::DriveAction(driveAction requestedDriveAction):
                                        m_distAutonMoveEncoderTicks("Auton Movement", 6000) {
    m_driveAction = requestedDriveAction;

}

void DriveAction::ActionInit() {
    DriveSubsystem* driveSubsystem = &Robot::GetInstance()->driveSubsystem;
    m_encoderStartUpPosition =  driveSubsystem->getRobotPosition();
}

CORE::COREAutonAction::actionStatus DriveAction::Action() {
    DriveSubsystem* driveSubsystem = &Robot::GetInstance()->driveSubsystem;
    double encoderValue = driveSubsystem->getRobotPosition();
    switch(m_driveAction) {
        case FORWARD:
            // Robot::GetInstance()->driveSubsystem.setMotorSpeed(0.5, DriveSide::BOTH);
            if(encoderValue < m_distAutonMoveEncoderTicks.Get() + m_encoderStartUpPosition){
                driveSubsystem->setMotorSpeed(0.5, DriveSide::BOTH);
            }
            break;
        case BACKWARD:
            if(encoderValue < m_distAutonMoveEncoderTicks.Get() + m_encoderStartUpPosition){
                driveSubsystem->setMotorSpeed(-0.5, DriveSide::BOTH);
            }
            break;
    }
    return COREAutonAction::actionStatus::END;
}

void DriveAction::ActionEnd() {

}