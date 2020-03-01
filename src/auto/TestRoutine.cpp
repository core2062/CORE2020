#include "TestRoutine.h"

TestRoutine::TestRoutine() : COREAuton("Test Routine") {}

void TestRoutine::AddNodes() {
    testNode = new Node(5, new ConveyorAction(CONVEYOR_ON));
    delayNode = new Node(3, new DelayAction());
    testNode2 = new Node(5, new ConveyorAction(CONVEYOR_OFF));
    AddFirstNode(testNode);
    testNode->AddNext(delayNode);
    delayNode->AddNext(testNode2);
}