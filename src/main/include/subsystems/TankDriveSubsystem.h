/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <ctre/Phoenix.h>

class TankDriveSubsystem : public frc::Subsystem
{
public: // PUBLIC METHODS
    TankDriveSubsystem();

    void InitDefaultCommand() override;
    
    void SetMotorOutputByPercentage(double left, double right);

private: // PRIVATE DATA
    std::unique_ptr<TalonSRX> m_left_front_motor;
    std::unique_ptr<TalonSRX> m_left_rear_motor;
    std::unique_ptr<TalonSRX> m_right_front_motor;
    std::unique_ptr<TalonSRX> m_right_rear_motor;

private: // PRIVATE METHODS
    
};
