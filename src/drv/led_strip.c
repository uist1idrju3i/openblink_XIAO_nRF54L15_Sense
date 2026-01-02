/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright (c) 2026 YAMASHIRO Yoshihiro All Rights
 * Reserved.
 */
/**
 * @file led_strip.c
 * @brief Implementation of LED strip driver
 * @details Implements functions for controlling LED strips
 */
#include "led_strip.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <zephyr/device.h>
#include <zephyr/drivers/led_strip.h>
#include <zephyr/logging/log.h>

#include "../lib/fn.h"

LOG_MODULE_REGISTER(drv_led_strip, LOG_LEVEL_DBG);

/** @brief GPIO specifications for switches */
static const struct device* kStrip = DEVICE_DT_GET(DT_NODELABEL(led_strip));
static struct led_rgb pixels[STRIP_NUM_PIXELS] = {0};

/**
 * @brief Initializes the LED strip subsystem
 *
 * @details Checks if the LED strip device is ready
 *
 * @return fn_t kSuccess if successful, kFailure otherwise
 */
fn_t drv_led_strip_init(void) {
  fn_t tmp_ret = kSuccess;
  if (true != device_is_ready(kStrip)) {
    tmp_ret = kFailure;
    LOG_ERR("Failed to get LED strip device");
  }
  if (kSuccess != drv_led_strip_update()) {
    tmp_ret = kFailure;
    LOG_ERR("Failed to clear LED strip");
  }

  return tmp_ret;
}

/**
 * @brief Updates the LED strip with new pixel data
 *
 * @return fn_t kSuccess if successful, kFailure otherwise
 */
fn_t drv_led_strip_update(void) {
  int rc = led_strip_update_rgb(kStrip, pixels, STRIP_NUM_PIXELS);
  if (0 < rc) {
    LOG_ERR("Couldn't update strip: %d", rc);
    return kFailure;
  }
  return kSuccess;
}

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
                       const uint8_t kGreen, const uint8_t kBlue) {
  if (STRIP_NUM_PIXELS <= kIndex) {
    LOG_ERR("Pixel index out of range: %d", kIndex);
    return kFailure;
  } else {
    pixels[kIndex].r = kRed;
    pixels[kIndex].g = kGreen;
    pixels[kIndex].b = kBlue;
  }
  return kSuccess;
}
