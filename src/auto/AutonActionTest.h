#pragma once

#include <string>
#include <CORERobotLib.h>
#include "DriveAction.h"
#include "IntakePowerCellsAction.h"
#include "LaunchBallsAction.h"
#include "ConveyorAction.h"
// #include "AutonActionTest.h"

using namespace CORE;
using namespace std;

class TestRoutine: public COREAuton {
public:
    TestRoutine();
    void AddNodes() override;
private:
    Node * testNode;
    Node * testNode2;
};
