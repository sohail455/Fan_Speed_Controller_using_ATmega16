/******************************************************************************
 *
 * Module: Mini Project3
 *
 * File Name: Mini_Project3.c
 *
 * Description: source file Mini Project3
 *
 * Author: Sohail Talaat
 *
 *******************************************************************************/

#include"dc_motor.h"
#include"lcd.h"
#include"lm35_sensor.h"
#include "adc.h"
#include<avr/io.h>
#include<util/delay.h>

void PWM_Timer0_Start(uint8 duty_cycle)
{
	TCNT0 = 0; //Set Timer Initial value

	OCR0  = duty_cycle; // Set Compare Value

	DDRB  = DDRB | (1<<PB3); //set PB3/OC0 as output pin --> pin where the PWM signal is generated from MC.

	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);

}

int main(void)
{
	uint8 temp = 0;
	ADC_ConfigType Config_Ptr = {INTERNAL_V,DIVISION_8};/*make a configuration structure and give it the wanted initial values*/
	LCD_init();/*initiate the lcd module*/
	DcMotor_Init();/*initiate the dc motor module*/
	ADC_init(&Config_Ptr);/*initiate the adc module according to the value of configuration structure */
	PWM_Timer0_Start(0);/*initiate timer0 to work as pwm*/
	temp = LM35_getTemperature();/*reading the temperature at first*/
	_delay_ms(300);/*wait until the reading be stable*/

	while(1)
	{
		temp = LM35_getTemperature();/*read the temperature ech iteration*/

		if(temp < 30)/*if the temp less than 30 then turn off the motor*/
		{
			DcMotor_Rotate(STOP, 0);
			LCD_displayStringRowColumn(0, 4, "Fan Is Off");
			LCD_displayStringRowColumn(1,4,"Temp = ");
			if(temp >= 100)
			{
				LCD_intgerToString(temp);
			}
			else
			{
				LCD_intgerToString(temp);
				LCD_displayCharacter(' ');
			}
		}
		else if((temp >= 30) && (temp < 60))/*if the temp is less than 60 and greater than 30 the turn on the motor with 25% of its speed*/
		{
			DcMotor_Rotate(CLOCKWISE, 25);
			LCD_displayStringRowColumn(0, 4, "Fan Is ON ");
			LCD_displayStringRowColumn(1,4,"Temp = ");
			if(temp >= 100)
			{
				LCD_intgerToString(temp);
			}
			else
			{
				LCD_intgerToString(temp);
				LCD_displayCharacter(' ');
			}
		}
		else if((temp >= 60) && (temp < 90))/*if the temp is less than 90 and greater than 60 the turn on the motor with 50% of its speed*/
		{

			DcMotor_Rotate(CLOCKWISE, 50);
			LCD_displayStringRowColumn(0, 4, "Fan Is ON ");
			LCD_displayStringRowColumn(1,4,"Temp = ");
			if(temp >= 100)
			{
				LCD_intgerToString(temp);
			}
			else
			{
				LCD_intgerToString(temp);
				LCD_displayCharacter(' ');
			}

		}
		else if((temp >= 90) && (temp < 120))/*if the temp is less than 120 and greater than 90 the turn on the motor with 75% of its speed*/
		{
			DcMotor_Rotate(CLOCKWISE, 75);
			LCD_displayStringRowColumn(0, 4, "Fan Is ON ");
			LCD_displayStringRowColumn(1,4,"Temp = ");
			if(temp >= 100)
			{
				LCD_intgerToString(temp);
			}
			else
			{
				LCD_intgerToString(temp);
				LCD_displayCharacter(' ');
			}
		}
		else if(temp >= 120)/*if the temp is greater than 120 the turn on the motor with 100% of its speed*/
		{
			DcMotor_Rotate(CLOCKWISE, 100);
			LCD_displayStringRowColumn(0, 4, "Fan Is ON ");
			LCD_displayStringRowColumn(1,4,"Temp = ");
			if(temp >= 100)
			{
				LCD_intgerToString(temp);
			}
			else
			{
				LCD_intgerToString(temp);
				LCD_displayCharacter(' ');
			}

		}

	}


}

