#pragma once

//#include "Robot.h"
#include "ctre/Phoenix.h"
#include <CORERobotLib.h>
#include "AHRS.h"
#include "COREFramework/COREScheduler.h"

#include <frc/Compressor.h>
#include <frc/DoubleSolenoid.h>
#include <frc/geometry/Pose2d.h>
#include <frc/geometry/Rotation2d.h>
#include "WaypointFollower/WaypointFollower.h"
#include "COREUtilities/CORETimer.h"

enum class DriveSide{LEFT = 1, RIGHT = 2, BOTH = 3};

class DriveSubsystem : public CORESubsystem, public CORETask {
public:
	DriveSubsystem();
	void robotInit() override;
	void teleopInit() override;
	void teleop() override;
	void teleopEnd() override;
	void preLoopTask() override;

	void initTalons();
	void autonInitTask() override;

	void setMotorSpeed(double speedInFraction, DriveSide whichSide);
	void setMotorSpeed(double leftPercent, double rightPercent);
	void fillCompressor();
	void toggleGear();
	void resetEncoders();
	void resetOdometry(Pose2d pose);
	Pose2d getPose();
	 m_odometry = Rotation2d(units::degree_t(GetHeading()));
	COREConstant<double> m_lookAhead, m_driveTurnkP;
	COREVector path;
    TalonSRX m_leftMaster, m_rightMaster, m_leftSlave, m_rightSlave;

private:
    COREConstant<double> m_etherAValue, m_etherBValue, m_etherQuickTurnValue, m_ticksPerInch;
    Compressor compressor;
	DoubleSolenoid m_leftDriveShifter, m_rightDriveShifter;
	bool m_highGear;
	double m_wheelbase = 20.8;
	double m_trackwidth = 25.881;
	AHRS *m_gyro;
    int count = 0;
};