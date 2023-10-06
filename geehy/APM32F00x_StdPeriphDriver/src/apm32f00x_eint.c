/*!
 * @file        apm32f00x_eint.c
 *
 * @brief       This file contains all the functions for the EINT peripheral
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

/* Includes */
#include "apm32f00x_eint.h"

/** @addtogroup APM32F00x_StdPeriphDriver
  @{
*/

/** @addtogroup EINT_Driver EINT Driver
  @{
*/

/** @defgroup EINT_Functions Functions
  @{
*/

/*!
 * @brief       Set the EINT peripheral registers to their default reset values
 *
 * @param       None
 *
 * @retval      None
 *
 * @note
 */
void EINT_Reset(void)
{
    EINT->CTRL1 = EINT_CTRL1_RESET_VALUE;
    EINT->CTRL2 = EINT_CTRL1_RESET_VALUE;
    EINT->CLR = EINT_CLR_RESET_VALUE;
}

/*!
 * @brief       EINT Configuration
 *
 * @param       port:       Specifies the External interrupt Port
 *
 * @param       trigger:    Specifies the External interrupt trigger
 *
 * @retval      None
 *
 * @note        When 'port' = EINT_PORT_TLI,
 *              'trigger' can't be EINT_TRIGGER_FALLING_LOW or EINT_TRIGGER_FALLING_RISING
 */
void EINT_Config(EINT_PORT_T port, EINT_TRIGGER_T trigger)
{
    if(port == EINT_PORT_A)
    {
        EINT->CTRL1_B.PAIT = trigger;
    }
    else if(port == EINT_PORT_B)
    {
        EINT->CTRL1_B.PBIT = trigger;
    }
    else if(port == EINT_PORT_C)
    {
        EINT->CTRL1_B.PCIT = trigger;
    }
    else if(port == EINT_PORT_D)
    {
        EINT->CTRL1_B.PDIT = trigger;
    }
    else if(port == EINT_PORT_TLI)
    {
        EINT->CTRL2_B.NMIT = trigger & 0X01;
    }
}

/*!
 * @brief       Clear the specified interrupt pending bits
 *
 * @param       port:   Specifies the external interrupt port
 *
 * @retval      None
 *
 * @note
 */
void EINT_ClearIntFlag(EINT_PORT_T port)
{
    EINT->CLR =  (uint32_t)(0x01 << port);
}

/**@} end of group EINT_Functions */
/**@} end of group EINT_Driver */
/**@} end of group APM32F00x_StdPeriphDriver */
