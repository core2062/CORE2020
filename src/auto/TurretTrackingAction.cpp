#include "TurretTrackingAction.h"
#include "Robot.h"

TurretTrackingAction::TurretTrackingAction(turretTrackingAction requestedTurretTrackingAction) {
    m_turretTrackingAction = requestedTurretTrackingAction;
}

void TurretTrackingAction::ActionInit() {
    TurretSubsystem* turretSubsystem = &Robot::GetInstance()->turretSubsystem;
    m_turretStartupPosition = turretSubsystem->turretPosition();
}

CORE::COREAutonAction::actionStatus TurretTrackingAction::Action() {
    TurretSubsystem* turretSubsystem = &Robot::GetInstance()->turretSubsystem;
    m_turretPosition = turretSubsystem->turretPosition();
    bool atLeftStop = m_turretPosition < (m_turretStartupPosition - 7000.0);
    bool atRightStop = m_turretPosition > (m_turretStartupPosition + 7000.0);
    switch(m_turretTrackingAction) {
        case TRACKING_ON: {
            double motorPercent = turretSubsystem->VisionMove(atLeftStop, atRightStop);
            Robot::GetInstance()->turretSubsystem.SetTurret(motorPercent);
            break;
        }
        case TRACKING_OFF: {
            Robot::GetInstance()->turretSubsystem.SetTurret(0.0);
            break;
        }
        default: break;
    }
    return COREAutonAction::actionStatus::END;
} 

void TurretTrackingAction::ActionEnd() {

}
