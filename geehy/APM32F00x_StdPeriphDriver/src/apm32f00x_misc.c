/*!
 * @file        apm32f00x_misc.c
 *
 * @brief       This file provides all the miscellaneous firmware functions.
 *              Include NVIC,SystemTick and Power management
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
#include "apm32f00x_misc.h"

/** @addtogroup APM32F00x_StdPeriphDriver
  @{
*/

/** @addtogroup MISC_Driver MISC Driver
  @{
*/

/** @addtogroup MISC_Functions Functions
  @{
*/

/*!
 * @brief       Enable NVIC request
 *
 * @param       irq:        The NVIC interrupt request, detailed in IRQn_Type
 *
 * @param       priority:   Specifies the priority needed to set
 *
 * @retval      None
 *
 * @note
 */
void NVIC_EnableIRQRequest(IRQn_Type irq, uint8_t priority)
{
    NVIC_SetPriority(irq, priority);

    NVIC_EnableIRQ(irq);
}

/*!
 * @brief       Disable NVIC request
 *
 * @param       irq:    The NVIC interrupt request, detailed in IRQn_Type
 *
 * @retval      None
 *
 * @note
 */
void NVIC_DisableIRQRequest(IRQn_Type irq)
{
    NVIC_DisableIRQ(irq);
}

/*!
 * @brief       Enter Wait Mode
 *
 * @param       None
 *
 * @retval      None
 *
 * @note
 */
void PMU_EnterWaitMode(void)
{
    SCB->SCR &= (uint32_t)(~(uint32_t)NVIC_LOWPOER_SLEEPDEEP);
    __WFI();
}

/*!
 * @brief       Enter Stop Mode with WFI instruction
 *
 * @param       None
 *
 * @retval      None
 *
 * @note
 */
void PMU_EnterHaltModeWFI(void)
{
    SCB->SCR |= NVIC_LOWPOER_SLEEPDEEP;
    __DSB();
    __WFI();
}

/*!
 * @brief       Enter Stop Mode with WFE instruction
 *
 * @param       None
 *
 * @retval      None
 *
 * @note
 */
void PMU_EnterHaltModeWFE(void)
{
    SCB->SCR |= NVIC_LOWPOER_SLEEPDEEP;
    __DSB();
    __WFE();
}

/**@} end of group MISC_Functions */
/**@} end of group MISC_Driver */
/**@} end of group APM32F00x_StdPeriphDriver */
