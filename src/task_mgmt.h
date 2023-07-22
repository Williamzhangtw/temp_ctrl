/*
 * Copyright © Williamzhangtw 2023
 * SPDX-License-Identifier: MIT
 */

/**
 * @file
 * @brief Task Management header.
 * Change Logs:
 * Date           Author       Notes
 * 2023-03-20     William
 */
#ifndef TASK_MGMT_H
#define TASK_MGMT_H

#include "stdint.h"
#include "stdbool.h"
#include "string.h"

enum TaskID
{
    ButtonTask,
    DisplayTask,
    UITasK,
    TimerTask,
    TempCtrlTask,
    TaskEnd
};

struct TaskInfo
{
    uint8_t id;
    bool en;
    bool ready;
    uint16_t ms;
    void (*fun)(void);
};

#endif
