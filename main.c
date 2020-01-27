/*
 * gpio challenge.c
 *
 * Created: 1/18/2020 11:34:52 AM
 * Author : ahmed
 */ 
#include "std_types.h"
#include "registers.h"
#include "gpio.h"
//#include "softwareDelay.h"
#include "led.h"
//#include "pushButton.h"
#include "interrupt.h"
#include "timers.h"
#include "dcMotor.h"

extern uint16_t u16_gISRCount;
/*This main function is for Repeating REQ8 for REQ10 and REQ12*/

/*
int main(void)
{
    Led_Init(LED_0);
	void timer0Init(T0_NORMAL_MODE,T0_OC0_DIS,T0_PRESCALER_8, 0, 0, T0_INTERRUPT_NORMAL);
	pushButtonInit(BTN_0);
	gpioPinWrite(GPIOC,BIT4,HIGH);
	uint8_t volatile pressCounter=1;
	uint16_t volatile delayCounter;
	uint8_t buttonStatus;
    while (1) 
    {
		Led_Off(LED_0);
		buttonStatus = pushButtonGetStatus(BTN_0);
		
		
		if (buttonStatus == Pressed)
		{
			timer0Stop();
			timer0Set(0);
			u16_gISRCount=0;
			Led_On(LED_0);
			
			for(delayCounter=0;delayCounter<20;delayCounter++)
			{
				
				buttonStatus = pushButtonGetStatus(BTN_0);
				if (buttonStatus == Pressed)
					pressCounter++;
			}
			
			if (pressCounter >1)
			timer0Stop();
			timer0Set(0);
			u16_gISRCount=0;
			timer0DelayMs(1000);
			
			Led_Off(LED_0);
		}
		
		
		
    } 
   
 
} */

/*This main function is for Repeating REQ9 for REQ10 and REQ12*/
/*
int main(void)
{
	Led_Init(LED_1);
	Led_Init(LED_2);
	Led_Init(LED_3);
	while (1)
	{
		Led_On(LED_1);
		
		timer0Stop();
		timer0Set(0);
		u16_gISRCount=0;
		timer0DelayMs(1000);
		
		Led_Off(LED_1);
		
		Led_On(LED_3);
		
		timer0Stop();
		timer0Set(0);
		u16_gISRCount=0;
		timer0DelayMs(1000);
		
		Led_Off(LED_3);
		
		Led_On(LED_2);
		
		timer0Stop();
		timer0Set(0);
		u16_gISRCount=0;
		timer0DelayMs(1000);
		
		Led_Off(LED_2);
	}
	
	return 0;
}
*/

/*This main is for REQ13*/
/*
int main(void)
{
	SREG = 0b10000000;
	Led_Init(LED_1);
	Led_Init(LED_2);
	Led_Init(LED_3);
	timer0Init(T0_NORMAL_MODE,T0_OC0_DIS,T0_PRESCALER_8,0,0,T0_POLLING);
	//uint8_t buttonStatus;
	while (1)
	{
		//buttonStatus = pushButtonGetStatus(BTN_0);
		
		Led_On(LED_1);
		
		timer0Stop();
		timer0Set(0);
		//u16_gISRCount=0;
		timer0DelayMs(1000);
		
		Led_Off(LED_1);
		
		
		Led_On(LED_3);
		
		timer0Stop();
		timer0Set(0);
		//u16_gISRCount=0;
		timer0DelayMs(1000);
		
		Led_Off(LED_3);
		
		Led_On(LED_2);
		
		timer0Stop();
		timer0Set(0);
		//u16_gISRCount=0;
		timer0DelayMs(1000);
		
		Led_Off(LED_2);
	}
	
	return 0;
} */
/*
int main (void)
{
	SREG = 0b10000000;
	
	Led_Init(LED_1);
	
	Led_Off(LED_1);
	timer0Init(T0_NORMAL_MODE,T0_OC0_DIS,T0_PRESCALER_1024,0,0,T0_INTERRUPT_NORMAL);
	//Led_Off(LED_1);
	while(1);
}*/

int main(void)
{
	/*SREG |= 0b10000000;
	gpioPinDirection(GPIOA,BIT0,OUTPUT);
	gpioPinWrite(GPIOA,BIT0,HIGH);
	timer0Init(T0_NORMAL_MODE,T0_OC0_DIS,T0_PRESCALER_8,0,0,T0_POLLING);
	//timer2SwPWM(0,F_8000);
	uint8_t speed=0;
	while (1)
	{
		timer0DelayMs(10);
		timer2SwPWM(speed++,F_8000);
		if(speed >= 256)
		  speed =0;
		//OCR2+=1;
	}
	
	return 0;*/
	
	SREG |=0b10000000;
	dcMotor1Enable();
	dcMotor2Enable();
	uint8_t u8_dutyCycle=0;
	Led_Init(LED_0);
	while (1)
	{
		
		for (u8_dutyCycle=0;u8_dutyCycle<255;u8_dutyCycle++)
		{
			MoveForward(u8_dutyCycle);
			timer0DelayMs(20);
		}
		
		for (u8_dutyCycle=255;u8_dutyCycle>0;u8_dutyCycle--)
		{
			MoveForward(u8_dutyCycle);
			timer0DelayMs(20);
		}
		
		/*Led_On(LED_0);
		timer0DelayMs(10);
		Led_Off(LED_0);
		timer0DelayMs(10);*/
	}
}