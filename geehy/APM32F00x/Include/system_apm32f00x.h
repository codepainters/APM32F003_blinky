/*!
 * @file        system_apm32f00x.h
 *
 * @brief       CMSIS Cortex-M0+ Device Peripheral Access Layer System Header File
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
#ifndef __SYSTEM_APM32F00X_H
#define __SYSTEM_APM32F00X_H

#ifdef __cplusplus
 extern "C" {
#endif

/** @addtogroup CMSIS
  @{
*/

/** @addtogroup APM32F00x_System
  * @brief APM32F00x system configuration
  @{
*/

/** @defgroup System_Functions
  @{
*/

extern void SystemInit(void);
extern uint32_t SystemCoreClock;
/**@} end of group System_Functions */
/**@} end of group APM32F00x_System */
/**@} end of group CMSIS */

#ifdef __cplusplus
}
#endif

#endif /*__SYSTEM_APM32F00X_H */
