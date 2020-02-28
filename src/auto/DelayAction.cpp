#include "DelayAction.h"

DelayAction::DelayAction() {

}

void DelayAction::ActionInit() {
}

CORE::COREAutonAction::actionStatus DelayAction::Action() {
    
    return COREAutonAction::actionStatus::CONTINUE;
} 

void DelayAction::ActionEnd() {

}
