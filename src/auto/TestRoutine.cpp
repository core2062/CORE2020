#include "TestRoutine.h"

TestRoutine::TestRoutine() : COREAuton("Drive Routine") {}

void TestRoutine::AddNodes() {
    testNode = new Node(5, new IntakePowerCellsAction(INTAKE));
    delayNode = new Node(3, new DelayAction());
    testNode2 = new Node(5, new IntakePowerCellsAction(STOP));
    AddFirstNode(testNode);
    testNode->AddNext(delayNode);
    delayNode->AddNext(testNode2);
}