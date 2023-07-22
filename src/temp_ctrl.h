/*
 * Copyright © Williamzhangtw 2023
 * SPDX-License-Identifier: MIT
 */

/**
 * @file
 * @brief Temperature control header.
 * Change Logs:
 * Date           Author       Notes
 * 2023-03-20     William      define APIs
 */

#ifndef TEMP_CTRL_H
#define TEMP_CTRL_H

#include <stdint.h>
#include <stdbool.h>
#define VALID_TEMP(x)   (x >= 100)
void ctrl_temp(float target);
/**
 *  @brief get the temperature in celsius °C.
 */
extern float get_temp(void);
extern void cooling(bool en);

#endif // TEMP_CTRL_H
