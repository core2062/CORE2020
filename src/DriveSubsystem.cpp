
#include <DriveSubsystem.h>
#include <Robot.h>

DriveSubsystem::DriveSubsystem() :
		m_odometry{frc::Rotation2d(units::degree_t(getHeading()))},
		m_driveTurnkP("Drive Turn P Value", .05),
		m_leftMaster(LEFT_FRONT_PORT),
		m_rightMaster(RIGHT_FRONT_PORT),
		m_leftSlave(LEFT_BACK_PORT),
		m_rightSlave(RIGHT_BACK_PORT),
		m_etherAValue("Ether A Value", .6),
        m_etherBValue("Ether B Value", .4),
		m_etherQuickTurnValue("Ether Quick Turn Value", 1.0),
        m_ticksPerInch("Ticks Per Inch", (4 * 3.1415) / 1024),
        m_leftDriveShifter(LEFT_DRIVE_SHIFTER_PCM, LEFT_DRIVE_SHIFTER_HIGH_GEAR_PORT, LEFT_DRIVE_SHIFTER_LOW_GEAR_PORT),
        m_rightDriveShifter(RIGHT_DRIVE_SHIFTER_PCM, RIGHT_DRIVE_SHIFTER_HIGH_GEAR_PORT, RIGHT_DRIVE_SHIFTER_LOW_GEAR_PORT) {

    try {
        m_gyro = new AHRS(SPI::Port::kMXP);
    } catch (std::exception ex) {
        CORELog::logError("Error initializing gyro: " + string(ex.what()));
    }
}

void DriveSubsystem::robotInit() {
	// Registers joystick axis and buttons, does inital setup for talons
	driverJoystick->RegisterAxis(CORE::COREJoystick::LEFT_STICK_Y);
	driverJoystick->RegisterAxis(CORE::COREJoystick::RIGHT_STICK_X);
	driverJoystick->RegisterButton(CORE::COREJoystick::RIGHT_TRIGGER);
    initTalons();
}

void DriveSubsystem::auton() {
  m_odometry.Update(frc::Rotation2d(units::degree_t(getHeading())),
                    units::meter_t(m_leftMaster.GetSelectedSensorPosition(0)),
                    units::meter_t(m_rightMaster.GetSelectedSensorPosition(0)));
}

void DriveSubsystem::teleopInit() {
	// Sets ether drive values, inits talons
	COREEtherDrive::SetAB(m_etherAValue.Get(), m_etherBValue.Get());
	COREEtherDrive::SetQuickturn(m_etherQuickTurnValue.Get());
	initTalons();
}

void DriveSubsystem::teleop() {
	// Code for teleop. Sets motor speed based on the values for the joystick, runs compressor,
	// toggles gears
    double mag = -driverJoystick->GetAxis(CORE::COREJoystick::JoystickAxis::LEFT_STICK_Y);
	double rot = driverJoystick->GetAxis(CORE::COREJoystick::JoystickAxis::RIGHT_STICK_X);

	VelocityPair speeds = COREEtherDrive::Calculate(mag, rot, .1);
	setMotorSpeed(speeds.left, speeds.right);
	SmartDashboard::PutNumber("Left side speed", speeds.left);
	SmartDashboard::PutNumber("Right side speed", speeds.right);
	SmartDashboard::PutNumber("Left side encoder", m_leftSlave.GetSelectedSensorPosition(0));
	SmartDashboard::PutNumber("Right side encoder", m_rightMaster.GetSelectedSensorPosition(0));

	if(driverJoystick->GetRisingEdge(CORE::COREJoystick::JoystickButton::RIGHT_TRIGGER)) {
		toggleGear();
	}
	fillCompressor();
}

void DriveSubsystem::setMotorSpeed(double speedInFraction, DriveSide whichSide) {
	// Sets motor speed based on drive side and desired speed
	if (whichSide == DriveSide::BOTH || whichSide == DriveSide::RIGHT) {
		m_rightMaster.Set(ControlMode::PercentOutput, speedInFraction);
		m_rightSlave.Set(ControlMode::PercentOutput, speedInFraction);
	}
	if (whichSide == DriveSide::BOTH || whichSide == DriveSide::LEFT) {
		m_leftMaster.Set(ControlMode::PercentOutput, speedInFraction);
		m_leftSlave.Set(ControlMode::PercentOutput, speedInFraction);
	}
}

void DriveSubsystem::setMotorSpeed(double leftPercent, double rightPercent) {
	// Sets speed based on percent output desired
	setMotorSpeed(leftPercent, DriveSide::LEFT);
	setMotorSpeed(rightPercent, DriveSide::RIGHT);
}

void DriveSubsystem::initTalons() {
	// Sets up talons
	m_leftMaster.Set(ControlMode::PercentOutput, 0);
	m_leftSlave.Set(ControlMode::PercentOutput, 0);
	m_rightMaster.Set(ControlMode::PercentOutput, 0);
	m_rightSlave.Set(ControlMode::PercentOutput, 0);

	// Encoder Functions
    m_leftSlave.SetStatusFramePeriod(StatusFrameEnhanced::Status_1_General, 10, 0);
    m_rightMaster.SetStatusFramePeriod(StatusFrameEnhanced::Status_1_General, 10, 0);

    m_leftSlave.ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice::CTRE_MagEncoder_Relative, 0, 0);
    m_rightMaster.ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice::CTRE_MagEncoder_Relative, 0, 0);

	m_leftSlave.SetSensorPhase(false);
    m_rightMaster.SetSensorPhase(true);

	// Motor Inversion
	m_leftMaster.SetInverted(false);
	m_leftSlave.SetInverted(false);
	m_rightMaster.SetInverted(true);
	m_rightSlave.SetInverted(true);
}

void DriveSubsystem::teleopEnd() {}

void DriveSubsystem::fillCompressor() {
	// Code to run the compressor. Maybe should be moved to Robot?
	if (compressor.GetPressureSwitchValue()) {
		compressor.SetClosedLoopControl(false);
	} else {
		compressor.SetClosedLoopControl(true);
	}
}

void DriveSubsystem::toggleGear() {
	// Shifts from high gear to low gear or vice versa
	if (m_highGear) {
		m_leftDriveShifter.Set(DoubleSolenoid::kForward);
		m_highGear = false;
	} else {
		m_leftDriveShifter.Set(DoubleSolenoid::kReverse);
		m_highGear = true;
	}
}

void DriveSubsystem::resetEncoders() {
	m_leftMaster.SetSelectedSensorPosition(0);
	m_leftSlave.SetSelectedSensorPosition(0);
	m_rightMaster.SetSelectedSensorPosition(0);
	m_rightSlave.SetSelectedSensorPosition(0);
}

double DriveSubsystem::getHeading() {
	return std::remainder(m_gyro->GetAngle(), 360) * (kGyroReversed ? -1.0 : 1.0);
}

void DriveSubsystem::resetOdometry(Pose2d pose) {
	resetEncoders();
	m_odometry.ResetPosition(pose, Rotation2d(units::degree_t(getHeading())));
}

Pose2d DriveSubsystem::getPose() {
	return m_odometry.GetPose();
}

double DriveSubsystem::getTurnRate() {
	return m_gyro->GetRate() * (kGyroReversed ? -1.0 : 1.0);
}

double DriveSubsystem::getAverageEncoderDistance() {
	return m_leftMaster.GetSelectedSensorPosition(0) + m_rightMaster.GetSelectedSensorPosition(0) / 2.0;
}

TalonSRX& DriveSubsystem::getRightMaster() {
	return m_rightMaster;
}

TalonSRX& DriveSubsystem::getRightSlave() {
	return m_rightSlave;
}

TalonSRX& DriveSubsystem::getLeftMaster() {
	return m_leftMaster;
}

TalonSRX& DriveSubsystem::getLeftSlave() {
	return m_leftSlave;
}


void DriveSubsystem::tankDriveVolts(units::volt_t l, units::volt_t r) {

}

void DriveSubsystem::setVelocity(double leftVelocity, double rightVelocity) {
	m_leftMaster.Set(ControlMode::Velocity, leftVelocity);
	m_leftSlave.Set(ControlMode::Velocity, leftVelocity);
	m_rightMaster.Set(ControlMode::Velocity, rightVelocity);
	m_rightSlave.Set(ControlMode::Velocity, rightVelocity);
}

kinematics::DifferentialWheelSpeeds DriveSubsystem::getWheelSpeeds() {
	  return {units::meters_per_second_t(m_leftMaster.),
          units::meters_per_second_t(m_rightEncoder.GetRate())};
}

void DriveSubsystem::setMaxOutput(double maxOutput) {
	m_drive.SetMaxOutput(maxOutput);
}