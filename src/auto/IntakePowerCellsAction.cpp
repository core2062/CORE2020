#include "IntakePowerCellsAction.h"

IntakePowerCellsAction::IntakePowerCellsAction(intakePowerCellsAction requestedIntakePowerCellAction) {
    m_intakePowerCellsAction = requestedIntakePowerCellAction;

}

void IntakePowerCellsAction::ActionInit() {

}

CORE::COREAutonAction::actionStatus IntakePowerCellsAction::Action() {
    switch(m_intakePowerCellsAction) {
        case INTAKE:
            Robot::GetInstance()->intakeSubsystem.SetIntake(0.2);
            break;
        case OUTTAKE:
            Robot::GetInstance()->intakeSubsystem.SetIntake(-0.2);
            break;
        case STOP:
            Robot::GetInstance()->intakeSubsystem.SetIntake(0);
            break;
    }
    return COREAutonAction::actionStatus::END;
}

void IntakePowerCellsAction::ActionEnd() {

}