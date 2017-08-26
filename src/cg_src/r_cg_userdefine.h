/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIESREGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2015, 2016 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_cg_userdefine.h
* Version      : Code Generator for RX23T V1.00.04.02 [29 Nov 2016]
* Device(s)    : R5F523T5AxFM
* Tool-Chain   : CCRX
* Description  : This file includes user definition.
* Creation Date: 2017/8/26
***********************************************************************************************************************/
#ifndef _USER_DEF_H
#define _USER_DEF_H

/***********************************************************************************************************************
User definitions
***********************************************************************************************************************/
#define FAST_INTERRUPT_VECTOR 0

/* Start user code for function. Do not edit comment generated here */
#define KEY1 PORT1.PIDR.BIT.B1
#define KEY2 PORT4.PIDR.BIT.B1
#define KEY3 PORT4.PIDR.BIT.B7

#define KEY_GO PORT0.PIDR.BIT.B2
#define KEY_BACK PORT9.PIDR.BIT.B2
#define KEY_LEFT PORT9.PIDR.BIT.B3
#define KEY_RIGHT PORTA.PIDR.BIT.B2

#define KEY_LEFT_Now PORT1.PIDR.BIT.B0
#define KEY_RIGHT_Now PORT4.PIDR.BIT.B0

#define KEY_STOP PORT7.PIDR.BIT.B5
#define KEY_START PORT7.PIDR.BIT.B6


#define LED1 PORT4.PODR.BIT.B3
#define LED2 PORT4.PODR.BIT.B5

void KeyScan(void);
void OLED_Display(void);
void Receive(void);
void Flag_Display(void);
void Receive_Data_Handling();
/* End user code. Do not edit comment generated here */
#endif
