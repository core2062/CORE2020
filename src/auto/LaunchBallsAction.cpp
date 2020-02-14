#include "LaunchBallsAction.h"

LaunchBallsAction::LaunchBallsAction(launchBallsAction requestedLaunchBallsAction) {
    m_launchBallsAction = requestedLaunchBallsAction;
}

void LaunchBallsAction::ActionInit() {
}

CORE::COREAutonAction::actionStatus LaunchBallsAction::Action() {
    switch(m_launchBallsAction) {
        case LAUNCH_LOCATION_ONE:
            // Robot::GetInstance()->launcherSubsystem.
            break;
        case LAUNCH_LOCATION_TWO:
            // Robot::GetInstance()->launcherSubsystem.
            break;
        case LAUNCH_LOCATION_THREE:
            // Robot::GetInstance()->launcherSubsystem.
            break;
        case LAUNCHER_OFF:
            // Robot::GetInstance()->launcherSubsystem.
            break;
    return COREAutonAction::actionStatus::END;
    }
}

void LaunchBallsAction::ActionEnd() {

}
