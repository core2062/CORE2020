#pragma once

#include <string>
#include <CORERobotLib.h>
#include "LaunchBallsAction.h"
#include "ConveyorAction.h"
#include "DriveAction.h"
#include "DelayAction.h"
// #include "AutonActionTest.h"

using namespace CORE;
using namespace std;

class ThreeBallRoutine: public COREAuton {
public:
    ThreeBallRoutine();
    void AddNodes() override;
private:
    Node * delayNode1;   
    Node * delayNode2;
    Node * launcherOnNode;
    Node * conveyorOnNode;
    Node * driveNode;
};
