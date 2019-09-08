/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "T34_XboxController.h"

class OI 
{
public: // PUBLIC METHODS
    OI();

    inline T34_XboxController * DriverCtrl() { return m_driver_ctrl.get(); }
    
private: // PRIVATE DATA
    std::unique_ptr<T34_XboxController> m_driver_ctrl;
};
