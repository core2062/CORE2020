#pragma once
#include <IntakeSubsystem.h>
#include <CORERobotLib.h>

using namespace CORE;

class IntakePowerCellsAction : public COREAutonAction {
public:
    IntakePowerCellsAction();
    void ActionInit() override;
    CORE::COREAutonAction::actionStatus Action() override;
    void ActionEnd() override;
};
