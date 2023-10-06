/*!
 * @file        apm32f00x_misc.h
 *
 * @brief       This file provides all the miscellaneous firmware functions prototype
 *
 * @version     V1.0.2
 *
 * @date        2023-03-31
 *
 * @attention
 *
 *  Copyright (C) 2023 Geehy Semiconductor
 *
 *  You may not use this file except in compliance with the
 *  GEEHY COPYRIGHT NOTICE (GEEHY SOFTWARE PACKAGE LICENSE).
 *
 *  The program is only for reference, which is distributed in the hope
 *  that it will be useful and instructional for customers to develop
 *  their software. Unless required by applicable law or agreed to in
 *  writing, the program is distributed on an "AS IS" BASIS, WITHOUT
 *  ANY WARRANTY OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the GEEHY SOFTWARE PACKAGE LICENSE for the governing permissions
 *  and limitations under the License.
 */

/* Define to prevent recursive inclusion */
#ifndef __APM32F00X_MISC_H
#define __APM32F00X_MISC_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes */
#include "apm32f00x.h"

/** @addtogroup APM32F00x_StdPeriphDriver
  @{
*/

/** @addtogroup MISC_Driver MISC Driver
  @{
*/

/** @defgroup MISC_Enumerations Enumerations
  @{
*/

/**
 * @brief    System low power mode
 */
typedef enum
{
    NVIC_LOWPOER_SEVONPEND          = 0x10,     /*!<    Low Power SEV on Pend */
    NVIC_LOWPOER_SLEEPDEEP          = 0x04,     /*!<    Low Power DEEPSLEEP request */
    NVIC_LOWPOER_SLEEPONEXIT        = 0x02      /*!<    Low Power Sleep on Exit */
} NVIC_LOWPOER_T;

/**@} end of group MISC_Enumerations */

/** @addtogroup MISC_Functions Functions
  @{
*/

/* NVIC */
void NVIC_EnableIRQRequest(IRQn_Type irq, uint8_t priority);
void NVIC_DisableIRQRequest(IRQn_Type irq);

/* PMU */
void PMU_EnterWaitMode(void);
void PMU_EnterHaltModeWFI(void);
void PMU_EnterHaltModeWFE(void);

/**@} end of group MISC_Functions */
/**@} end of group MISC_Driver */
/**@} end of group APM32F00x_StdPeriphDriver */

#ifdef __cplusplus
}
#endif

#endif /* __APM32F0X_MISC_H */
