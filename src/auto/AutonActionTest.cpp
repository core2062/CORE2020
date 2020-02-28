#include "AutonActionTest.h"

TestRoutine::TestRoutine() : COREAuton("Drive Routine") {}

void TestRoutine::AddNodes() {
    testNode = new Node(5, new DriveAction(FORWARD));
    AddFirstNode(testNode);
}
