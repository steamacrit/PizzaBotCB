/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"
#include "commands/StopDriveCommand.h"

StopDriveCommand::StopDriveCommand() 
    : m_is_finished(false)
{
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::m_drive_system);
}

// Called just before this Command runs the first time
void StopDriveCommand::Initialize() { }

// Called repeatedly when this Command is scheduled to run
void StopDriveCommand::Execute() 
{
    Robot::m_drive_system.SetMotorOutputByPercentage(0.0, 0.0);
    m_is_finished = true;
}

// Make this return true when this Command no longer needs to run execute()
bool StopDriveCommand::IsFinished() 
{ 
    return m_is_finished; 
}

// Called once after isFinished returns true
void StopDriveCommand::End() 
{
    Robot::m_drive_system.SetMotorOutputByPercentage(0.0, 0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void StopDriveCommand::Interrupted() 
{
    End();
}
