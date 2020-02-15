#pragma once

#include <string>
#include <CORERobotLib.h>
#include "LaunchBallsAction.h"
// #include "AutonActionTest.h"

using namespace CORE;
using namespace std;

class ThreeBallRoutine: public COREAuton {
public:
    ThreeBallRoutine();
    void AddNodes() override;
private:
    Node * threeBallNode;
};
