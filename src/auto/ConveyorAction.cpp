#include "ConveyorAction.h"
#include "Robot.h"

ConveyorAction::ConveyorAction(conveyorAction requestedConveyorAction) {
    m_conveyorAction = requestedConveyorAction;

}

void ConveyorAction::ActionInit() {

}

CORE::COREAutonAction::actionStatus ConveyorAction::Action() {
    switch(m_conveyorAction) {
        case CONVEYOR_ON:
            Robot::GetInstance()->conveyorSubsystem.setMotor(-0.25, -0.25);
            break;
        case CONVEYOR_OFF:
            Robot::GetInstance()->conveyorSubsystem.setMotor(0, 0);
            break;
    }
    return COREAutonAction::actionStatus::END;
}

void ConveyorAction::ActionEnd() {

}