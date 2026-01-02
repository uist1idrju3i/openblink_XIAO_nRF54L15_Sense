/*
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: Copyright (c) 2025 ViXion Inc. All Rights Reserved.
 */
/**
 * @file main.c
 * @brief Main entry point for the OpenBlink firmware
 * @details This file contains the main function and factory reset detection
 * logic
 */
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

#include "app/init.h"
#include "drv/gpio.h"

LOG_MODULE_REGISTER(main, LOG_LEVEL_DBG);

/**
 * @brief Main function of the OpenBlink firmware
 *
 * @return EXIT_FAILURE if the program exits unexpectedly
 */
int main(void) {
  while (1) {
    k_msleep(1000);
  }
  return EXIT_FAILURE;
}
