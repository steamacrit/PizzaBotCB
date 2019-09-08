/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"
#include "commands/TeleopDriveCommand.h"

TeleopDriveCommand::TeleopDriveCommand() 
{
    // Use Requires() here to declare subsystem dependencies
    Requires(&Robot::m_drive_system);

    SetInterruptible(true);
}

// Called just before this Command runs the first time
void TeleopDriveCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void TeleopDriveCommand::Execute() 
{
    Robot::m_drive_system.SetMotorOutputByPercentage(
        Robot::m_oi.DriverCtrl()->GetYDB(frc::GenericHID::JoystickHand::kLeftHand), 
        Robot::m_oi.DriverCtrl()->GetYDB(frc::GenericHID::JoystickHand::kRightHand));    
}

// Make this return true when this Command no longer needs to run execute()
bool TeleopDriveCommand::IsFinished() 
{ 
    return false; 
}

// Called once after isFinished returns true
void TeleopDriveCommand::End() 
{
    Robot::m_drive_system.SetMotorOutputByPercentage(0.0, 0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TeleopDriveCommand::Interrupted() 
{
    End();
}
