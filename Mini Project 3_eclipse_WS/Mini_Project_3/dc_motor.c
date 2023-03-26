/******************************************************************************
 *
 * Module: Dc Motor
 *
 * File Name: DcMotor.c
 *
 * Description: source file for Dc Motort driver
 *
 * Author: Sohail Talaat
 *
 *******************************************************************************/
#include"dc_motor.h"
#include"gpio.h"/*To use gpio driver functions*/
#include<avr/io.h>/*To use avr register*/
/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the Dc Motor driver.
 */

void DcMotor_Init(void)
{
	GPIO_setupPinDirection(INPUT1_PORT, INPUT1_PIN, PIN_OUTPUT);/*set the direction of first pin in L293D chip*/
	GPIO_setupPinDirection(INPUT2_PORT, INPUT2_PIN, PIN_OUTPUT);/*set the direction of second pin in L293D chip*/
	/*initial values to stop the motor at the beginning*/
	GPIO_writePin(INPUT1_PORT, INPUT1_PIN, LOGIC_LOW);
	GPIO_writePin(INPUT2_PORT, INPUT2_PIN, LOGIC_LOW);
	OCR0 = 0;


}

/*
 * Description :
 * Function responsible for setting the speed and the rotation direction to Dc Motor driver.
 */

void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	/*the speed must not exceed 100*/
	if(speed > 100)
	{
		speed = 100;

	}
	/*if state is to rotate clockwise then configure output and set the speed*/
	if(state == CLOCKWISE)
	{
		GPIO_writePin(INPUT1_PORT, INPUT1_PIN, LOGIC_LOW);
		GPIO_writePin(INPUT2_PORT, INPUT2_PIN, LOGIC_HIGH);
		OCR0 = 255*((float)speed/100);

	}
	/*if state is to rotate anti_clockwise then configure output and set the speed*/
	else if(state == ANTI_CLOCKWISE)
	{
		GPIO_writePin(INPUT1_PORT, INPUT1_PIN, LOGIC_HIGH);
		GPIO_writePin(INPUT2_PORT, INPUT2_PIN, LOGIC_LOW);
		OCR0 = 255*((float)speed/100);

	}
	/*if state is to stop then configure output and set the speed = 0*/
	else if(state == STOP)
	{
		GPIO_writePin(INPUT1_PORT, INPUT1_PIN, LOGIC_LOW);
		GPIO_writePin(INPUT2_PORT, INPUT2_PIN, LOGIC_LOW);
		OCR0 = 255*((float)speed/100);
	}


}
