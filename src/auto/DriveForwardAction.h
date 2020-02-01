#pragma once
#include <DriveSubsystem.h>
#include <CORERobotLib.h>

using namespace CORE;

class DriveForwardAction : public COREAutonAction {
public:
    DriveForwardAction();
    void ActionInit() override;
    CORE::COREAutonAction::actionStatus Action() override;
    void ActionEnd() override;
};
