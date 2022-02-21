/*
 * App.c
 *
 *  Created on: Apr 6, 2021
 *      Author: Compu Store
 */

#include "avr\delay.h"
#include "Types.h"
#include "Macros.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "Keypad_Interface.h"
#include "App_FunctionsandDefine.h"

int main (void)
{
	u8 LOC_u8PressedValue = 'F';
	DIO_vdSetPortDirection(LCD_U8_DATA_PORT,PORT_OUTPUT);
	DIO_vdSetPortDirection(LCD_U8_CTRL_PORT,PORT_OUTPUT);
	s32 App_u8FirstOperand=0, App_u8SecondOperand=0;
	u8 App_u8OperandSendingTimes=0;
	u8 App_u8Operator ='F', App_u8OperatorSendingTimes=0;
	s32 App_u2ResultOperation=0;
	s32 App_s8OperatorAssign1=1, App_s8OperatorAssign2=1;
	u8 alarm=0;
	u8 stringWarning []="Wrong Input";
	u8 stringUndefined[]="Undefined";
	Keypad_vdInitialization();
	LCD_vdInitialization();

	while(1)
	{
		Keypad_vdGetPressedKey(&LOC_u8PressedValue);
		if(LOC_u8PressedValue != 'F')
		{
			LCD_vdSendChar(LOC_u8PressedValue);
			//If It was an operator...
			if((LOC_u8PressedValue >= 0x2A && LOC_u8PressedValue <=0x2F) || (LOC_u8PressedValue ==0x25 ))
			{
				App_u8OperatorSendingTimes++;
				if(App_u8OperandSendingTimes==0 || App_u8OperandSendingTimes>App_u8OperatorSendingTimes)
				{
					App_vdOparatorCheck(&LOC_u8PressedValue, &App_s8OperatorAssign1, &App_s8OperatorAssign2, &App_u8OperandSendingTimes, &App_u8OperatorSendingTimes);
				}
				else
				{
					App_u8Operator= LOC_u8PressedValue;
				}
			}
			//Assign operator --> Break
			else if(LOC_u8PressedValue== '=')
			{
				App_u8FirstOperand= App_u8FirstOperand*App_s8OperatorAssign1;
				App_u8SecondOperand=App_u8SecondOperand*App_s8OperatorAssign2;
				if(App_u8OperatorSendingTimes==0 && App_u8OperandSendingTimes>=1)
				{
					LCD_vdWriteNum(App_u8FirstOperand);
				}
				else
				{
					if(App_s8OperatorAssign1==0 || App_s8OperatorAssign2==0)
					{
						 LCD_vdWriteString(stringWarning);
					}
					else if(alarm ==1)
					{
						 LCD_vdWriteString(stringUndefined);
					}
					else
					{
						App_s32OperationChosen(&App_u8FirstOperand,&App_u8SecondOperand, &App_u8Operator, &App_u2ResultOperation, &alarm );
						LCD_vdWriteNum(App_u2ResultOperation);
					}
				}
				break;
			}
			//Operand
			else
			{
				App_u8OperandSendingTimes++;
				if(App_u8OperatorSendingTimes==0)
				{
					LOC_u8PressedValue-=48;
					App_u8FirstOperand = App_u8FirstOperand*10 + (LOC_u8PressedValue);

				}
				else
				{
					LOC_u8PressedValue-=48;
					App_u8SecondOperand = App_u8SecondOperand*10 + LOC_u8PressedValue;
				}
			}
			LOC_u8PressedValue = 'F';
		}
	}
	return 0;

}
