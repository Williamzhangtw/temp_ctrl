/*
 * Copyright © Williamzhangtw 2023
 * SPDX-License-Identifier: MIT
 */

/**
 * @file
 * @brief Power management header.
 * Change Logs:
 * Date           Author       Notes
 * 2023-03-20     William      define APIs
 */

#ifndef POWER_MANAGEMENT_H
#define POWER_MANAGEMENT_H

#include <stdint.h>

extern bool g_sleep;
void go_sleep(void);
void mcu_reboot(void);
extern bool prepare_sleep(void);

#endif // POWER_MANAGEMENT_H
