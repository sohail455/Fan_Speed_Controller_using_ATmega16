/******************************************************************************
 *
 * Module: Dc Motor
 *
 * File Name: DcMotor.h
 *
 * Description: header file for Dc Motor driver
 *
 * Author: Sohail Talaat
 *
 *******************************************************************************/

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
#include"std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define INPUT1_PORT      PORTB_ID/*the port of the first input of L293D*/
#define INPUT1_PIN       PIN0_ID/*the pin of the first input of L293D*/

#define INPUT2_PORT      PORTB_ID/*the port of the second input of L293D*/
#define INPUT2_PIN       PIN1_ID/*the pin of the first input of L293D*/

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum
{
	STOP,CLOCKWISE,ANTI_CLOCKWISE

}DcMotor_State;/*enum to choose the state of dc motor*/

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the Dc Motor driver.
 */
void DcMotor_Init(void);

/*
 * Description :
 * Function responsible for setting the speed and the rotation direction to Dc Motor driver.
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed);




#endif /* DC_MOTOR_H_ */
