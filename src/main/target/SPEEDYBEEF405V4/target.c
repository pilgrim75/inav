/*
 * This file is part of INAV Project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * Alternatively, the contents of this file may be used under the terms
 * of the GNU General Public License Version 3, as described below:
 *
 * This file is free software: you may copy, redistribute and/or modify
 * it under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * This file is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
 * Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see http://www.gnu.org/licenses/.
 */
#include <stdint.h>

#include "platform.h"

#include "drivers/bus.h"
#include "drivers/io.h"
#include "drivers/pwm_mapping.h"
#include "drivers/timer.h"
#include "drivers/pinio.h"
#include "drivers/sensor.h"

BUSDEV_REGISTER_SPI_TAG(busdev_icm42688,  DEVHW_ICM42605, ICM42605_SPI_BUS,  ICM42605_CS_PIN,  NONE,  0,  DEVFLAGS_NONE,  IMU_ICM42605_ALIGN);

timerHardware_t timerHardware[] = {
    // PATCHED for RC405/VOGUN XV board
    // Motors remapped to match BF resource dump
    DEF_TIM(TIM8,   CH1, PC6,  TIM_USE_OUTPUT_AUTO, 1, 0), // S1 - MOTOR1 (was PB6/TIM4)
    DEF_TIM(TIM8,   CH2, PC7,  TIM_USE_OUTPUT_AUTO, 1, 0), // S2 - MOTOR2 (was PB7/TIM4)
    DEF_TIM(TIM8,   CH3, PC8,  TIM_USE_OUTPUT_AUTO, 1, 0), // S3 - MOTOR3 (was PB0/TIM3)
    DEF_TIM(TIM8,   CH4, PC9,  TIM_USE_OUTPUT_AUTO, 1, 0), // S4 - MOTOR4 (was PB1/TIM3)
    DEF_TIM(TIM2,   CH1, PA15, TIM_USE_OUTPUT_AUTO, 1, 0), // S5 - MOTOR5 (was PC8/TIM8)
    DEF_TIM(TIM1,   CH1, PA8,  TIM_USE_OUTPUT_AUTO, 1, 0), // S6 - MOTOR6 (was PC9/TIM8)
    DEF_TIM(TIM2,   CH3, PB10, TIM_USE_OUTPUT_AUTO, 1, 0), // S7 - MOTOR7 OK
    DEF_TIM(TIM2,   CH4, PB11, TIM_USE_OUTPUT_AUTO, 1, 0), // S8 - MOTOR8 (was PA15/TIM2)

    DEF_TIM(TIM3,   CH4, PB1,  TIM_USE_OUTPUT_AUTO, 1, 0), // S9  (was PB15/TIM12)
    DEF_TIM(TIM3,   CH3, PB0,  TIM_USE_OUTPUT_AUTO, 1, 0), // S10 (was PB14/TIM12)

    DEF_TIM(TIM3,   CH4, PB1,  TIM_USE_LED,   0, 0), // LED strip PB1 (was PA8/TIM1)
};

const int timerHardwareCount = sizeof(timerHardware) / sizeof(timerHardware[0]);
