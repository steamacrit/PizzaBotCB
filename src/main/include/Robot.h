/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/TimedRobot.h>
#include <frc/commands/Command.h>
#include <frc/smartdashboard/SendableChooser.h>

#include "OI.h"
#include "subsystems/TankDriveSubsystem.h"
#include "commands/TeleopDriveCommand.h"
#include "commands/StopDriveCommand.h"
#include "commands/MyAutoCommand.h"

class Robot : public frc::TimedRobot 
{
public: // PUBLIC DATA
    static TankDriveSubsystem m_drive_system;
    static OI m_oi;

public: // PUBLIC METHODS
    void RobotInit() override;
    void RobotPeriodic() override;
    void DisabledInit() override;
    void DisabledPeriodic() override;
    void AutonomousInit() override;
    void AutonomousPeriodic() override;
    void TeleopInit() override;
    void TeleopPeriodic() override;
    void TestPeriodic() override;

 private: // PRIVATE DATA
    // Have it null by default so that if testing teleop it
    // doesn't have undefined behavior and potentially crash.
    frc::Command* m_autonomousCommand = nullptr;
    TeleopDriveCommand m_teleop_drive;
    StopDriveCommand m_stop_drive;
    MyAutoCommand m_myAuto;
    frc::SendableChooser<frc::Command*> m_chooser;
};
