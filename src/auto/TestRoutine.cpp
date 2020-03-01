#include "TestRoutine.h"

TestRoutine::TestRoutine() : COREAuton("Test Routine") {}

void TestRoutine::AddNodes() {
    testNode = new Node(5, new LaunchBallsAction(LAUNCHER_ON));
    delayNode = new Node(3, new DelayAction());
    testNode2 = new Node(5, new LaunchBallsAction(LAUNCHER_OFF));
    AddFirstNode(testNode);
    testNode->AddNext(delayNode);
    delayNode->AddNext(testNode2);
}