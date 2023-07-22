/*
 * Copyright © Williamzhangtw 2023
 * SPDX-License-Identifier: MIT
 */

/**
 * @file
 * @brief Task Management.
 * Change Logs:
 * Date           Author       Notes
 * 2023-03-20     William
 */
#include "task_mgmt.h"
#include "stdlib.h"
#include "task_mgmt.h"
#include "temp_ctrl.h"
#include "usr_data.h"
#include "pwr_mgmt.h"
#include "ui.h"

uint16_t *timer_array;

void control_temp(void)
{
    temp_ctrl(target_temp);
}

void scan_encoder()
{
    
}

void encoder_event(void)
{
    ui();
}

struct TaskInfo tasks[3] =
    {
        {ButtonTask, true, false, 10, scan_encoder()},
        {DisplayTask, true, false, 100, update_display()},
        {UITasK, true, false, 10, display_status()}};
        {TempCtrlTask, true, false, 10, control_temp()}};

void tasks_init(void)
{
    uint16_t *timer_array = malloc(TaskEnd * sizeof(uint16_t));
    for (uint8_t i = 0; i < TaskEnd; i++)
    {
        timer_array[i] = tasks[i].ms;
    }
}

void tasks_mgmt(void)
{
    for (uint8_t i = 0; i < TaskEnd; i++)
    {
        if (tasks[i].en == true)
        {
            if (timer_array[i] > 0)
            {
                timer_array[i]--;
            }
            else
            {
                tasks[i].ready = true;
                timer_array[i] = tasks[i].ms;
            }
        }
    }
}

/**
 * Enables or disables a task with the given ID.
 *
 * @param task_id The ID of the task to enable or disable.
 * @param enable True to enable the task, false to disable it.
 */
void enable_task(int task_id, bool enable)
{
    tasks[task_id].en = enable;
    tasks[task_id].ready = false;
}

void tasks_process()
{
    for (uint8_t i = 0; i < TaskEnd; i++)
    {
        if (tasks[i].ready == true)
        {
            if (tasks[i].fun != NULL)
            {
                tasks[i].fun();
            }
        }
    }
}
