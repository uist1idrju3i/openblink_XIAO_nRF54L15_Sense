/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright (c) 2026 YAMASHIRO Yoshihiro All Rights
 * Reserved.
 */
/**
 * @file led_strip.h
 * @brief LED strip driver interface
 * @details Provides functions for controlling LED strips
 */
#ifndef DRV_LED_STRIP_H
#define DRV_LED_STRIP_H
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <zephyr/drivers/led_strip.h>

#include "../lib/fn.h"

#if DT_NODE_HAS_PROP(DT_NODELABEL(led_strip), chain_length)
#define STRIP_NUM_PIXELS DT_PROP(DT_NODELABEL(led_strip), chain_length)
#else
#error "LED strip chain_length property not found"
#endif

/**
 * @brief Initializes the LED strip subsystem
 *
 * @return fn_t kSuccess if successful, kFailure otherwise
 */
fn_t drv_led_strip_init(void);

/**
 * @brief Updates the LED strip with new pixel data
 *
 * @return fn_t kSuccess if successful, kFailure otherwise
 */
fn_t drv_led_strip_update(void);

/**
 * @brief Sets the color of a specific pixel on the LED strip
 *
 * @param kIndex The index of the pixel to set
 * @param kRed The red component (0-255)
 * @param kGreen The green component (0-255)
 * @param kBlue The blue component (0-255)
 * @return fn_t kSuccess if successful, kFailure otherwise
 */
fn_t drv_led_strip_set(const size_t kIndex, const uint8_t kRed,
                       const uint8_t kGreen, const uint8_t kBlue);

#endif
