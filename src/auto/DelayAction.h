#pragma once

#include <CORERobotLib.h>
#include "LauncherSubsystem.h"
#include "Robot.h"

using namespace CORE;

class DelayAction : public COREAutonAction {
public:
    DelayAction();
    void ActionInit() override;
    CORE::COREAutonAction::actionStatus Action() override;
    void ActionEnd() override;
private:

};