/*
 * Copyright © Williamzhangtw 2023
 * SPDX-License-Identifier: MIT
 */

/**
 * @file
 * @brief Temperature control.
 * Change Logs:
 * Date           Author       Notes
 * 2023-03-20     William
 */
#include "temp_ctrl.h"
#include "usr_data.h"
/**
 * @brief control temperature logic
 * @param unit in celsius °C
 */
void ctrl_temp(float target)
{
    float temp = get_temp();
    if (VALID_TEMP(temp))
    {
        if (temp > target_temp)
        {
            cooling(true);
        }
        else
        {
            cooling(false);
        }
    }
    else // sensor err
    {
        cooling(false);
    }
}