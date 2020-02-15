#include "LaunchBallsAction.h"

LaunchBallsAction::LaunchBallsAction(launchBallsAction requestedLaunchBallsAction) {
    m_launchBallsAction = requestedLaunchBallsAction;
}

void LaunchBallsAction::ActionInit() {
}

CORE::COREAutonAction::actionStatus LaunchBallsAction::Action() {
    switch(m_launchBallsAction) {
        case LAUNCH_LOCATION_ONE:
            Robot::GetInstance()->launcherSubsystem.launcherOn(true);
            break;
        case LAUNCH_LOCATION_TWO:
            Robot::GetInstance()->launcherSubsystem.launcherOn(true);
            break;
        case LAUNCH_LOCATION_THREE:
            Robot::GetInstance()->launcherSubsystem.launcherOn(true);
            break;
        case LAUNCHER_OFF:
            Robot::GetInstance()->launcherSubsystem.launcherOn(false);
            break;
    }
    return COREAutonAction::actionStatus::END;
} 

void LaunchBallsAction::ActionEnd() {

}
