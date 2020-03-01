// #pragma once

// #include <CORERobotLib.h>
// #include "TurretSubsystem.h"

// using namespace CORE;

// enum launchBallsAction {
//     TRACKING_ON,
//     TRACKING_OFF
// };

// class TurretTrackingAction : public COREAutonAction {
// public:
//     TurretTrackingAction(turretTrackingAction requestedLaunchBallsAction);
//     void ActionInit() override;
//     CORE::COREAutonAction::actionStatus Action() override;
//     void ActionEnd() override;
// private:
//     launchBallsAction m_launchBallsAction;
// };