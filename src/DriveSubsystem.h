#pragma once

//#include "Robot.h"
#include <CORERobotLib.h>
#include <ctre/Phoenix.h>
#include <AHRS.h>
#include <COREFramework/COREScheduler.h>

#include <frc/Compressor.h>
#include <frc/DoubleSolenoid.h>
#include <frc/geometry/Pose2d.h>
#include <frc/geometry/Rotation2d.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/kinematics/DifferentialDriveWheelSpeeds.h>
#include <frc/kinematics/DifferentialDriveKinematics.h>
#include <frc/kinematics/DifferentialDriveOdometry.h>
#include <Constants.h>

#define WHEEL_CIRCUMFERENCE_METERS
#define SENSOR_UNITS_PER_ROTATION 

enum class DriveSide{LEFT = 1, RIGHT = 2, BOTH = 3};

class DriveSubsystem : public CORESubsystem {
public:
	DriveSubsystem();
	void robotInit() override;
	void teleopInit() override;
	void teleop() override;
	void auton();
	void teleopEnd() override;

	void initTalons();

	void setMotorSpeed(double speedInFraction, DriveSide whichSide);
	void setMotorSpeed(double leftPercent, double rightPercent);
	void fillCompressor();
	void toggleGear();
	void resetEncoders();
	void resetOdometry(Pose2d pose);
	Pose2d getPose();
	double getHeading();
	double getTurnRate();
	void setMaxOutput(double maxOutput);
	double getAverageEncoderDistance();
	void tankDriveVolts(units::volt_t l, units::volt_t r);
	TalonSRX& getRightMaster();
	TalonSRX& getLeftMaster();
	TalonSRX& getRightSlave();
	TalonSRX& getLeftSlave();
	void setVelocity(double leftVelocity, double rightVelocity);
	DifferentialDriveWheelSpeeds getWheelSpeeds();
	SpeedControllerGroup m_leftMotors{m_leftSlave, m_leftMaster};
	SpeedControllerGroup m_rightMotors{m_rightSlave, m_leftMaster};
	DifferentialDrive m_drive{m_leftMotors, m_rightMotors};
	void setMaxOutput(double maxOutput);

	DifferentialDriveOdometry m_odometry;
	COREConstant<double> m_lookAhead, m_driveTurnkP;
	COREVector path;
private:
    TalonSRX m_leftMaster, m_rightMaster, m_leftSlave, m_rightSlave;
    COREConstant<double> m_etherAValue, m_etherBValue, m_etherQuickTurnValue, m_ticksPerInch;
    DoubleSolenoid m_leftDriveShifter, m_rightDriveShifter;
    bool m_highGear;
    Compressor compressor;
	double m_wheelbase = 20.8;
	double m_trackwidth = 25.881;
	AHRS * m_gyro;
    int count = 0;
};
