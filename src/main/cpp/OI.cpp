/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"
#include "RobotMap.h"
#include <frc/WPILib.h>

OI::OI() 
{
    m_driver_ctrl.reset(new T34_XboxController(RobotMap::DRIVER1_JOYSTICK_PORT));
}
