/*!
 * @file        apm32f00x_eint.h
 *
 * @brief       This file contains all functions prototype, enumeration and macros for the EINT peripheral
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
#ifndef __APM32F00X_EXTI_H
#define __APM32F00X_EXTI_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes */
#include "apm32f00x.h"

/** @addtogroup APM32F00x_StdPeriphDriver
  @{
*/

/** @addtogroup EINT_Driver EINT Driver
  @{
*/

/** @defgroup EINT_Macros Macros
  @{
*/

/* EINT register reset value */
#define EINT_CTRL1_RESET_VALUE          ((uint32_t)(0x00))
#define EINT_CTRL2_RESET_VALUE          ((uint32_t)(0x00))
#define EINT_CLR_RESET_VALUE            ((uint32_t)(0x00))

/**@} end of group EINT_Macros */

/** @defgroup EINT_Enumerations Enumerations
  @{
*/

/**
 * @brief   External interrupt trigger
 */
typedef enum
{
    EINT_TRIGGER_FALLING_LOW        = ((uint8_t)0X00),
    EINT_TRIGGER_RISING             = ((uint8_t)0X01),
    EINT_TRIGGER_FALLING            = ((uint8_t)0X02),
    EINT_TRIGGER_FALLING_RISING     = ((uint8_t)0X03),
} EINT_TRIGGER_T;

/**
 * @brief   External interrupt port definition
 */
typedef enum
{
    EINT_PORT_A         = ((uint8_t)0X00),
    EINT_PORT_B         = ((uint8_t)0X01),
    EINT_PORT_C         = ((uint8_t)0X02),
    EINT_PORT_D         = ((uint8_t)0X03),
    EINT_PORT_TLI       = ((uint8_t)0X06),
} EINT_PORT_T;

/**@} end of group EINT_Enumerations */

/** @defgroup EINT_Functions Functions
  @{
*/

void EINT_Reset(void);
void EINT_Config(EINT_PORT_T port, EINT_TRIGGER_T trigger);
void EINT_ClearIntFlag(EINT_PORT_T port);

/**@} end of group EINT_Functions */
/**@} end of group EINT_Driver */
/**@} end of group APM32F00x_StdPeriphDriver */

#ifdef __cplusplus
}
#endif

#endif /* __APM32F00X_EINT_H */
