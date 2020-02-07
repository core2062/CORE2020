#pragma once

#include <DriveSubsystem.h>
#include <CORERobotLib.h>

using namespace CORE;

enum driveForwardAction {
    FORWARD,
    BACKWARD,
    STOP
};

class DriveForwardAction : public COREAutonAction {
public:
    DriveForwardAction(driveForwardAction requestedDriveForwardAction);
    void ActionInit() override;
    CORE::COREAutonAction::actionStatus Action() override;
    void ActionEnd() override;
private:
    driveForwardAction m_driveForwardAction;
};
