#include <Autonomous/Auton.h>

Autonomous::Autonomous() : COREAuton("Test Auto") {}

void Autonomous::AddNodes() {
    m_drivePath = new Node(5, new PathFinderAction());
    AddFirstNode(m_drivePath);
}
