#include "ThreeBallRoutine.h"

ThreeBallRoutine::ThreeBallRoutine() : COREAuton("Three Ball Routine") {}

void ThreeBallRoutine::AddNodes() {
    conveyorOnNode = new Node(5, new ());
    autonNode2 = new Node(5, new AutonomousAction2());
    AddFirstNode(autonNode1);
    autonNode1->AddNext(autonNode2);
}
