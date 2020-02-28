#include "ThreeBallRoutine.h"

ThreeBallRoutine::ThreeBallRoutine() : COREAuton("Three Ball Routine") {}

void ThreeBallRoutine::AddNodes() {
    delayNode = new Node(5, new DelayAction());
    launcherOnNode = new Node(5, new LaunchBallsAction(LAUNCHER_ON));
    conveyorOnNode = new Node(5, new ConveyorAction(CONVEYOR_ON));
    driveNode = new Node(5, new DriveAction(FORWARD));
    AddFirstNode(delayNode);
    delayNode->AddNext(launcherOnNode);
    launcherOnNode->AddNext(conveyorOnNode);
    conveyorOnNode->AddNext(driveNode);
}
