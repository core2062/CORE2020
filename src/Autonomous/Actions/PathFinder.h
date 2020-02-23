
#pragma once

#include "CORERobotLib.h"

using namespace CORE;

class PathFinderAction : public COREAutonAction {
public:
    explicit PathFinderAction();
    void ActionInit() override;
    actionStatus Action() override;
    void ActionEnd() override;
private:
};