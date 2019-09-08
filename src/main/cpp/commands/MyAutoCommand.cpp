/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/MyAutoCommand.h"
#include "Robot.h"

MyAutoCommand::MyAutoCommand() 
{
    // Use Requires() here to declare subsystem dependencies
    Requires(&Robot::m_drive_system);
    SetInterruptible(true);
}

// Called just before this Command runs the first time
void MyAutoCommand::Initialize() 
{
    m_is_finished = false;
    m_step = 0;
    m_stop_watch.Start();
}

// Called repeatedly when this Command is scheduled to run
void MyAutoCommand::Execute() 
{
    // Step 0 = Move forward for 5 seconds
    // Step 1 = Rotate left for 3 second
    // Step 2 = Move forward for 5 seconds

    switch (m_step)
    {
        case 0:
            if (m_stop_watch.HasPeriodPassedSec(5.0))
            {
                m_step++;
                Robot::m_drive_system.SetMotorOutputByPercentage(0.0, 0.0);
                m_stop_watch.Reset();
            }
            else
                Robot::m_drive_system.SetMotorOutputByPercentage(0.5, 0.5);
            
            break;
        case 1:
            if (m_stop_watch.HasPeriodPassedSec(3.0))
            {
                m_step++;
                Robot::m_drive_system.SetMotorOutputByPercentage(0.0, 0.0);
                m_stop_watch.Reset();
            }
            else
                Robot::m_drive_system.SetMotorOutputByPercentage(-0.25, 0.25);
            
            break;
        case 2:              
            if (m_stop_watch.HasPeriodPassedSec(5.0))
            {
                m_step++;
                Robot::m_drive_system.SetMotorOutputByPercentage(0.0, 0.0);
                m_stop_watch.Reset();
            }
            else
                Robot::m_drive_system.SetMotorOutputByPercentage(0.5, 0.5);
            
            break;  
        default:
            Robot::m_drive_system.SetMotorOutputByPercentage(0.0, 0.0);
            m_is_finished = true;
    }
}

// Make this return true when this Command no longer needs to run execute()
bool MyAutoCommand::IsFinished() 
{ 
    return m_is_finished; 
}

// Called once after isFinished returns true
void MyAutoCommand::End() 
{
    Robot::m_drive_system.SetMotorOutputByPercentage(0.0, 0.0);    
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MyAutoCommand::Interrupted() 
{
    End();
}
