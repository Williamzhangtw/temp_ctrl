/*
 * Copyright © Williamzhangtw 2023
 * SPDX-License-Identifier: MIT
 */

/**
 * @file
 * @brief User Interface.
 * Change Logs:
 * Date           Author       Notes
 * 2023-03-20     William
 */
#include "temp_ctrl.h"
#include "usr_data.h"
#include "pwr_mgmt.h"
#include "ui.h"

uint32_t time_stamp;

void status_display(void)
{
    if((get_time() - time_stamp) > 2000){
        if(VALID_TEMP(get_temp())){
            show(get_temp());
        }else{
            show("S-E");
        }
    }
}

void ui(void)
{
    switch (rot_enc_evt)
    {
    case ROT_ROTATE:
        time_stamp = get_time();
        target_temp + rot_steps * 0.1;
        show(target_temp);
        save_usr_data();
        break;
    case ROT_LONG_PRESS:
        if(!g_sleep){
            g_sleep = true;
            go_sleep();
        }else{
            mcu_reboot();
        }
        break;
    default:
        break;
    }
}