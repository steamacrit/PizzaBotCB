/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Command.h>
#include "T34_Timer.h"

class MyAutoCommand : public frc::Command 
{
public: // PUBLIC METHODS
    MyAutoCommand();

    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;

private: // PRIVATE DATA
    T34_StopWatch m_stop_watch;
    bool m_is_finished;
    int32_t m_step;
};
