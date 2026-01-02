/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright (c) 2025 ViXion Inc. All Rights Reserved.
 */
/**
 * @file gpio.h
 * @brief GPIO driver interface
 * @details Provides functions for controlling LEDs and reading switch states
 */
#ifndef DRV_GPIO_H
#define DRV_GPIO_H

#include <stdbool.h>

#include "../lib/fn.h"

/**
 * @typedef drv_gpio_t
 * @brief Enumeration of GPIO pins for switches and LEDs
 */
typedef enum {
  kDrvGpioSW1,  /**< Switch 1 */
  kDrvGpioLED1, /**< LED 1 */
} drv_gpio_t;

/**
 * @brief Initializes the GPIO subsystem
 *
 * @return fn_t kSuccess if successful, kFailure otherwise
 */
fn_t drv_gpio_init(void);

/**
 * @brief Gets the current state of a GPIO pin
 *
 * @param kTgt Target GPIO pin
 * @return true if the pin is active (switch pressed)
 * @return false if the pin is inactive (switch released)
 */
bool drv_gpio_get(const drv_gpio_t kTgt);

/**
 * @brief Sets the state of a GPIO pin
 *
 * @param kTgt Target GPIO pin
 * @param kReq Requested state (true for active, false for inactive)
 * @return fn_t kSuccess if successful, kFailure otherwise
 */
fn_t drv_gpio_set(const drv_gpio_t kTgt, const bool kReq);

#endif
