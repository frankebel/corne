// Copyright 2026 splitkb.com (support@splitkb.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include_next <mcuconf.h>

#undef RP_PWM_USE_PWM5
#define RP_PWM_USE_PWM5 TRUE

#undef RP_I2C_USE_I2C0
#define RP_I2C_USE_I2C0 TRUE

#undef RP_SPI_USE_SPI1
#define RP_SPI_USE_SPI1 TRUE
