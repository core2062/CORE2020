#pragma once

#include <CORERobotLib.h>
#include "LauncherSubsystem.h"
#include "Robot.h"

using namespace CORE;

enum launchBallsAction {
    LAUNCH_LOCATION_ONE,
    LAUNCH_LOCATION_TWO,
    LAUNCH_LOCATION_THREE,
    LAUNCHER_OFF
};

class LaunchBallsAction : public COREAutonAction {
public:
    LaunchBallsAction(launchBallsAction requestedLaunchBallsAction);
    void ActionInit() override;
    CORE::COREAutonAction::actionStatus Action() override;
    void ActionEnd() override;
private:
    launchBallsAction m_launchBallsAction;
};