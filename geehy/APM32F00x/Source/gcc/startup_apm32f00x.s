/*!
 * @file       startup_apm32f00x.S
 *
 * @brief      CMSIS Cortex-M0 PLUS based Core Device Startup File for Device startup_apm32l072
 *
 * @version    V1.0.0
 *
 * @date       2023-03-31
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

  .syntax unified
  .cpu cortex-m0plus
  .fpu softvfp
  .thumb

.global g_apm32_Vectors
.global Default_Handler

.word _start_address_init_data
.word _start_address_data
.word _end_address_data
.word _start_address_bss
.word _end_address_bss

  .section .text.Reset_Handler
  .weak Reset_Handler
  .type Reset_Handler, %function

// Reset handler routine
Reset_Handler:
// User Stack and Heap initialization
  ldr   r0, =_end_stack
  mov   sp, r0

  ldr r0, =_start_address_data
  ldr r1, =_end_address_data
  ldr r2, =_start_address_init_data
  movs r3, #0
  b L_loop0_0

L_loop0:
  ldr r4, [r2, r3]
  str r4, [r0, r3]
  adds r3, r3, #4

L_loop0_0:
  adds r4, r0, r3
  cmp r4, r1
  bcc L_loop0

  ldr r2, =_start_address_bss
  ldr r4, =_end_address_bss
  movs r3, #0
  b L_loop1

L_loop2:
  str  r3, [r2]
  adds r2, r2, #4

L_loop1:
  cmp r2, r4
  bcc L_loop2

  bl  SystemInit
  bl __libc_init_array
  bl main

L_loop3:
    b L_loop3

.size Reset_Handler, .-Reset_Handler

// This is the code that gets called when the processor receives an unexpected interrupt.
    .section .text.Default_Handler,"ax",%progbits
Default_Handler:
L_Loop_infinite:
  b L_Loop_infinite
  .size Default_Handler, .-Default_Handler

// The minimal vector table for a Cortex M0 Plus.
   .section .apm32_isr_vector,"a",%progbits
  .type g_apm32_Vectors, %object
  .size g_apm32_Vectors, .-g_apm32_Vectors

// Vector Table Mapped to Address 0 at Reset
g_apm32_Vectors:

  .word _end_stack                          // Top of Stack
  .word Reset_Handler                       // Reset Handler
  .word NMI_Handler                         // NMI Handler
  .word HardFault_Handler                   // Hard Fault Handler
  .word 0                                   // Reserved
  .word 0                                   // Reserved
  .word 0                                   // Reserved
  .word 0                                   // Reserved
  .word 0                                   // Reserved
  .word 0                                   // Reserved
  .word 0                                   // Reserved
  .word SVC_Handler                         // SVCall Handler
  .word 0                                   // Reserved
  .word 0                                   // Reserved
  .word PendSV_Handler                      // PendSV Handler
  .word SysTick_Handler                     // SysTick Handler
  .word 0                                   // Reserved
  .word WUPT_IRQHandler                     // Wakeup timer
  .word RCM_IRQHandler                      // Clock controler interrupt
  .word EINTA_IRQHandler                    // Port A external interrupts
  .word EINTB_IRQHandler                    // Port B external interrupts
  .word EINTC_IRQHandler                    // Port C external interrupts
  .word EINTD_IRQHandler                    // Port D external interrupts
  .word 0                                   // Reserved
  .word 0                                   // Reserved
  .word 0                                   // Reserved
  .word SPI_IRQHandler                      // SPI Interrupt
  .word TMR1_UT_IRQHandler                  // TIMER1 update/overflow/underflow/trigger/break interrupt
  .word TMR1_CC_IRQHandler                  // TIMER1 capture/compare interrupt
  .word TMR2_UO_IRQHandler                  // TIMER2 update /overflow interrupt
  .word TMR2_CC_IRQHandler                  // TIMER2 capture/compare interrupt
  .word 0                                   // Reserved
  .word 0                                   // Reserved
  .word USART1_TX_IRQHandler                // USART1 TX interrupt
  .word USART1_RX_IRQHandler                // USART1 RX interrupt
  .word IIC_IRQHandler                      // I2C Interrupt
  .word 0                                   // Reserved
  .word 0                                   // Reserved
  .word ADC_IRQHandler                      // ADC interrupt
  .word TMR4_IRQHandler                     // TIMER4 interrupt
  .word FLASH_IRQHandler                    // Flash interrupt
  .word USART3_TX_IRQHandler                // USART3 TX interrupt
  .word USART3_RX_IRQHandler                // USART3 RX interrupt
  .word USART2_TX_IRQHandler                // USART2 TX interrupt
  .word USART2_RX_IRQHandler                // USART2 RX interrupt
  .word TMR1A_UT_IRQHandler                 // TIMER1A update/overflow/underflow/trigger/break interrupt
  .word TMR1A_CC_IRQHandler                 // TIMER1A capture/compare interrupt

// Default exception/interrupt handler

  .weak NMI_Handler
  .thumb_set NMI_Handler,Default_Handler

  .weak HardFault_Handler
  .thumb_set HardFault_Handler,Default_Handler

  .weak SVC_Handler
  .thumb_set SVC_Handler,Default_Handler

  .weak PendSV_Handler
  .thumb_set PendSV_Handler,Default_Handler

  .weak SysTick_Handler
  .thumb_set SysTick_Handler,Default_Handler

  .weak WUPT_IRQHandler
  .thumb_set WUPT_IRQHandler,Default_Handler

  .weak RCM_IRQHandler
  .thumb_set RCM_IRQHandler,Default_Handler

  .weak EINTA_IRQHandler
  .thumb_set EINTA_IRQHandler,Default_Handler

  .weak EINTB_IRQHandler
  .thumb_set EINTB_IRQHandler,Default_Handler

  .weak EINTC_IRQHandler
  .thumb_set EINTC_IRQHandler,Default_Handler

  .weak EINTD_IRQHandler
  .thumb_set EINTD_IRQHandler,Default_Handler

  .weak SPI_IRQHandler
  .thumb_set SPI_IRQHandler,Default_Handler

  .weak TMR1_UT_IRQHandler
  .thumb_set TMR1_UT_IRQHandler,Default_Handler

  .weak TMR1_CC_IRQHandler
  .thumb_set TMR1_CC_IRQHandler,Default_Handler

  .weak TMR2_UO_IRQHandler
  .thumb_set TMR2_UO_IRQHandler,Default_Handler

  .weak TMR2_CC_IRQHandler
  .thumb_set TMR2_CC_IRQHandler,Default_Handler

  .weak USART1_TX_IRQHandler
  .thumb_set USART1_TX_IRQHandler,Default_Handler

  .weak USART1_RX_IRQHandler
  .thumb_set USART1_RX_IRQHandler,Default_Handler

  .weak IIC_IRQHandler
  .thumb_set IIC_IRQHandler,Default_Handler

  .weak ADC_IRQHandler
  .thumb_set ADC_IRQHandler,Default_Handler

  .weak TMR4_IRQHandler
  .thumb_set TMR4_IRQHandler,Default_Handler

  .weak FLASH_IRQHandler
  .thumb_set FLASH_IRQHandler,Default_Handler

  .weak USART3_TX_IRQHandler
  .thumb_set USART3_TX_IRQHandler,Default_Handler

  .weak USART3_RX_IRQHandler
  .thumb_set USART3_RX_IRQHandler,Default_Handler

  .weak USART2_TX_IRQHandler
  .thumb_set USART2_TX_IRQHandler,Default_Handler

  .weak USART2_RX_IRQHandler
  .thumb_set USART2_RX_IRQHandler,Default_Handler

  .weak TMR1A_UT_IRQHandler
  .thumb_set TMR1A_UT_IRQHandler,Default_Handler

  .weak TMR1A_CC_IRQHandler
  .thumb_set TMR1A_CC_IRQHandler,Default_Handler
