#include "LauncherSubsystem.h"

using namespace CORE;

LauncherSubsystem::LauncherSubsystem() : 
                                        m_launcherMotor(BOTTOM_LAUNCHER_MOTOR_PORT), 
                                        m_launcherSpeed("Launcher Velocity", 0.42),
                                        m_reverseSpeed("Reverse Speed", 0.25) {
}

void LauncherSubsystem::robotInit() {
    operatorJoystick->RegisterButton(CORE::COREJoystick::JoystickButton::B_BUTTON);
    operatorJoystick->RegisterButton(CORE::COREJoystick::JoystickButton::DPAD_S);
}

void LauncherSubsystem::teleopInit() {
    m_launcherOn = false;
}

void LauncherSubsystem::teleop() {
    if (!m_launcherOn && operatorJoystick->GetRisingEdge(CORE::COREJoystick::JoystickButton::B_BUTTON)) {
        m_launcherOn = true;
    } else if (m_launcherOn && operatorJoystick->GetRisingEdge(CORE::COREJoystick::JoystickButton::B_BUTTON)) {
        m_launcherOn = false;
    }
    if (operatorJoystick->GetButton(CORE::COREJoystick::JoystickButton::DPAD_S)) {
         m_launcherMotor.Set(ControlMode::PercentOutput, m_reverseSpeed.Get());
    }
    launcherOn(m_launcherOn);
}

void LauncherSubsystem::launcherOn(bool m_launcherOn) {
    double motorSpeed = m_launcherSpeed.Get();
    if (m_launcherOn) {
        m_launcherMotor.Set(ControlMode::PercentOutput, motorSpeed);
    } else {
        m_launcherMotor.Set(ControlMode::PercentOutput, 0.0);
    }

}
