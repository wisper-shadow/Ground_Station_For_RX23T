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
* File Name    : r_cg_main.c
* Version      : Code Generator for RX23T V1.00.04.02 [29 Nov 2016]
* Device(s)    : R5F523T5AxFM
* Tool-Chain   : CCRX
* Description  : This file implements main function.
* Creation Date: 2017/8/13
***********************************************************************************************************************/

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
#define Data_STX        0x0A
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_cgc.h"
#include "r_cg_port.h"
#include "r_cg_sci.h"
/* Start user code for include. Do not edit comment generated here */
#include <stdbool.h>
#include "../src/oled/oled.h"
#include "../src/oled/bmp.h"
#include "../src/delay/delay.h"
//#include "../src/oled/oledfont.h"
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
uint8_t SCI1_get_char;
uint8_t SCI1_Receive_Data[12];

uint8_t SCI_Send_Num[10];
uint8_t buff[12]= {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x10,0xac,0xad};
uint8_t Distance = 0;
uint8_t Coo_x = 0,Coo_y = 0;
uint8_t flag_display = 0;
uint8_t i = 0;

bool sci1_trans = false;
bool start_receive = false;

void SCI1_TransIntHandler(void)
{
    sci1_trans = true;
}

void SCI1_IntHandler(void)
{
    static uint8_t i = 0;
    if(start_receive)
    {
        SCI1_Receive_Data[i] = SCI1_get_char;
        if(SCI1_get_char == '\t')
            SCI1_Receive_Data[i] = ' ';
        i++;
        if(i == 11)
        {
            i = 0;
            start_receive = false;
        }
    }
    if(SCI1_get_char == Data_STX)
        start_receive = true;
    R_SCI1_Serial_Receive(&SCI1_get_char,1);
}

void Data_Caculate(void)
{
    Coo_x = (SCI1_Receive_Data[0] - 48) * 100 + (SCI1_Receive_Data[1] - 48) * 10 + (SCI1_Receive_Data[2] - 48);
    Coo_y = (SCI1_Receive_Data[4] - 48) * 100 + (SCI1_Receive_Data[5] - 48) * 10 + (SCI1_Receive_Data[6] - 48);
    Distance = (SCI1_Receive_Data[8] - 48) * 100 + (SCI1_Receive_Data[9] - 48) * 10 + (SCI1_Receive_Data[10] - 48);
}

/* End user code. Do not edit comment generated here */


static void R_MAIN_UserInit(void);
/***********************************************************************************************************************
* Function Name: main
* Description  : This function implements main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void main(void)
{
    R_MAIN_UserInit();
    /* Start user code. Do not edit comment generated here */
	OLED_Init();			//初始化OLED
	OLED_Clear();
//	R_SCI1_Serial_Receive(SCI1_Receive_Data,15);
    while (1U)
    {
    	KeyScan();
    	Data_Caculate();
    	OLED_Display();
//    	OLED_ShowString(0,3,SCI1_Receive_Data,16);
//    	if(SCI1_Receive_Data[0]<48||SCI1_Receive_Data[0]>57)
//    	{
//    		SCI1_Receive_Data[0] = ' ';
//    	}
    	//OLED_ShowChar(x,3,SCI1_Receive_Data[0],16);
//    	SCI1_Receive_Data[0] = ' ';
//    	x+=8;
//    	if(x>=96)
//    		x=0;
    	Flag_Display();
    }
    /* End user code. Do not edit comment generated here */
}
/***********************************************************************************************************************
* Function Name: R_MAIN_UserInit
* Description  : This function adds user code before implementing main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_MAIN_UserInit(void)
{
    /* Start user code. Do not edit comment generated here */
	R_SCI1_Start();
	R_SCI1_Serial_Receive(&SCI1_get_char,1);
	/* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
void clear_str(uint8_t * const str, uint16_t length)
{
	int i;
	for(i=0;i<length-1;i++)
	{
		str[i] = 0;
	}
}
void LED1_Twinkle(void)
{
	LED1 = 1;
	delay_ms(50);
	LED1 = 0;
}
void LED2_Twinkle(void)
{
	LED2 = 1;
	delay_ms(50);
	LED2 = 0;
}
void KeyScan(void)
{
	if(KEY1 == 0)
	{
		delay_ms(5);
		if(KEY1 == 0)
		{
			R_SCI1_Serial_Send(&buff[6],1);
			LED2_Twinkle();
		}//while(KEY1==0);
	}
	if(KEY2 == 0)
		{
			delay_ms(5);
			if(KEY2 == 0)
			{
				LED2_Twinkle();
				R_SCI1_Serial_Send(&buff[11],1);
			}
		}
	if(KEY3 == 0)
	{
		delay_ms(5);
		if(KEY3 == 0)
		{
			LED2_Twinkle();
			R_SCI1_Serial_Send(&buff[10],1);
		}
	}
	if(KEY_GO == 0)
	{
		delay_ms(5);
		if(KEY_GO == 0)
		{
			LED2_Twinkle();
			R_SCI1_Serial_Send(&buff[0],1);
			OLED_ShowCHinese(110,6,6);
		}//while(KEY_GO == 0);
	}
	if(KEY_BACK == 0)
	{
		delay_ms(5);
		if(KEY_BACK == 0)
		{
			LED2_Twinkle();
			R_SCI1_Serial_Send(&buff[1],1);
			OLED_ShowCHinese(110,6,7);

		}//while(KEY_BACK == 0);
	}
	if(KEY_LEFT == 0)
	{
		delay_ms(5);
		if(KEY_LEFT == 0)
		{
			LED2_Twinkle();
			R_SCI1_Serial_Send(&buff[2],1);
			OLED_ShowCHinese(110,6,8);
		}//while(KEY_LEFT == 0);
	}
	if(KEY_RIGHT == 0)
	{
		delay_ms(5);
		if(KEY_RIGHT == 0)
		{
			LED2_Twinkle();
			R_SCI1_Serial_Send(&buff[3],1);
			OLED_ShowCHinese(110,6,9);
		}//while(KEY_RIGHT == 0);
	}
	if(KEY_START == 0)
	{
		delay_ms(5);
		if(KEY_START == 0)
		{
			LED2_Twinkle();
			R_SCI1_Serial_Send(&buff[4],1);
			OLED_ShowCHinese(110,3,10);
		}//while(KEY_START == 0);
	}
	if(KEY_STOP == 0)
	{
		delay_ms(5);
		if(KEY_STOP == 0)
		{
			LED2_Twinkle();
			R_SCI1_Serial_Send(&buff[5],1);
			OLED_ShowCHinese(110,3,11);
		}//while(KEY_STOP == 0);
	}
	if(KEY_LEFT_Now == 0)
	{
		delay_ms(5);
		if(KEY_LEFT_Now == 0)
		{
			LED2_Twinkle();
			R_SCI1_Serial_Send(&buff[7],1);
		}//while(KEY_STOP == 0);
	}
	if(KEY_RIGHT_Now == 0)
	{
		delay_ms(5);
		if(KEY_RIGHT_Now == 0)
		{
			LED2_Twinkle();
			R_SCI1_Serial_Send(&buff[8],1);
		}//while(KEY_STOP == 0);
	}
}
void OLED_Display(void)
{
	//OLED_Clear();
	OLED_ShowCHinese(0,0,0); //地
	OLED_ShowCHinese(18,0,1);//面
	OLED_ShowCHinese(36,0,2);//控
	OLED_ShowCHinese(54,0,3);//制
	OLED_ShowCHinese(72,0,4);//中
	OLED_ShowCHinese(90,0,5);//心
	OLED_ShowString(0,3,"Distance: ",16);
	OLED_ShowNum(85,3,Distance,3,16);
	OLED_ShowString(0,6,"Coo: ",16);
	OLED_ShowNum(40,6,Coo_x,3,16);
	OLED_ShowNum(70,6,Coo_y,3,16);
}

void Flag_Display(void)
{
	flag_display++;
	if(flag_display==200)
	{
		OLED_ShowString(108,0,"sw",16);//sw
	}
	if(flag_display==400)
	{
		flag_display = 0;
		OLED_ShowString(108,0,"  ",16);
	}
}
/* End user code. Do not edit comment generated here */
