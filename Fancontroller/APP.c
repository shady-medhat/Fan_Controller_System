/*
 * APP.c
 *
 *  Created on: Oct 14, 2023
 *      Author: shady
 */

#include "lcd.h"
#include "adc.h"
#include <avr/io.h>
#include "DC.h"
#include "lm35_sensor.h"
#include "PWM.h"

static uint8 tempreture; /* global variable to hold the tempreture and static because it only belongs to this file*/

typedef enum
{
	OFF,ON
}Fan_State;

Fan_State state;
/* Enumeration to ease the use of the state */

/*function responsible to detect the state of the fan and its speed*/
void APP_Fanprocessing(void)
{

	if(LM35_getTemperature()< 30)
	{
		state = OFF;
		DcMotor_Rotate(Stop,0);
        PWM_Timer0_Start(duty_cycle);  /*if under 30 stop fan*/
	}
	else if(LM35_getTemperature()>= 30 &&LM35_getTemperature()<60)
	{
        state = ON;
        DcMotor_Rotate(Clockwise  ,25);
        PWM_Timer0_Start(duty_cycle);   /*if under 60 fan speed 25%*/
	}
	else if(LM35_getTemperature()>= 60 &&LM35_getTemperature()<90)
	{
		state = ON;
		DcMotor_Rotate(Clockwise  ,50);
        PWM_Timer0_Start(duty_cycle); /*if under 90 fan speed 50%*/
	}
	else if(LM35_getTemperature()>= 90 &&LM35_getTemperature()<100)
	{
		state = ON;
		DcMotor_Rotate(Clockwise  ,75);
        PWM_Timer0_Start(duty_cycle); /*if under 100 fan speed 75%*/
	}
	else if(LM35_getTemperature()>= 100 &&LM35_getTemperature()<120)
	{
		state = ON;
		DcMotor_Rotate(Clockwise  ,100);
        PWM_Timer0_Start(duty_cycle);   /*if under 120 fan speed 100%*/

	}




}


int main (void)
{
	/* initializing PWM , Motor, and LCD*/
	PWM_Timer0_init();
	DcMotor_Init();
	LCD_init();
	/* displaying string required on LCD*/
	LCD_displayStringRowColumn(0, 2, "Fan is   ");
	LCD_displayStringRowColumn(1, 2, "Temp=  C");



	/* Create configuration structure for ADC driver  */

    ADC_ConfigType ADC_Configurations={INTERNAL,F_CPU_8};


	/* Initialize ADC driver */


	ADC_init(&ADC_Configurations);




	while(1)
	{

		tempreture = LM35_getTemperature(); /* detecting the tempreture using sensor and put value converted by ADC in variable tempreture*/
        APP_Fanprocessing(); /* calling the setting funtion */

		LCD_moveCursor(0,9); /* moving cursor to required place to display the fan state*/
		/* Displaying the fan state according to state variable*/
		if (state == OFF)
		{
		 LCD_displayString(" OFF ");
		}
		else if (state == ON)
		{
		 LCD_displayString(" ON ");
		 /* In case the digital value is two character print space in the next digit place */
		 LCD_displayCharacter(' ');
		}

		LCD_moveCursor(1,9); /* moving cursor to place to display tempreture*/
		/* Displaying the Temperature according to Tempreture variable*/
		if(tempreture >= 100)
		{
		 LCD_intgerToString(tempreture);
		}
		else
		{
		 LCD_intgerToString(tempreture);
		/* In case the digital value is two or one digits print space in the next digit place */
		 LCD_displayCharacter(' ');
		}

	}
}

