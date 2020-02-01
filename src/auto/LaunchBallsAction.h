#pragma once
#include <CORERobotLib.h>
#include <LauncherSubsystem.h>

using namespace CORE;


class LaunchBallsAction : public COREAutonAction {
public:
    LaunchBallsAction();
    void ActionInit() override;
    CORE::COREAutonAction::actionStatus Action() override;
    void ActionEnd() override;
};