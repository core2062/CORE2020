#include "AutonActionTest.h"

TestRoutine::TestRoutine() : COREAuton("Drive Routine") {}

void TestRoutine::AddNodes() {
    testNode = new Node(5, new IntakePowerCellsAction(INTAKE));
    testNode2 = new Node(5, new IntakePowerCellsAction(STOP));
    AddFirstNode(testNode);
    testNode->AddNext(testNode2);
}
