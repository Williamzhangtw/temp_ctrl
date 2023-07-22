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

#ifndef USR_DATA_H
#define USR_DATA_H

#include <stdint.h>

extern float target_temp;


void load_usr_data(void);
void save_usr_data(void);

#endif // USR_DATA_H
