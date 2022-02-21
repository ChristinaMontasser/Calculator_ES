/*
 * App_FunctionandDefine.c
 *
 *  Created on: Apr 6, 2021
 *      Author: Compu Store
 */

#include "Types.h"

#include "App_FunctionsandDefine.h"
void App_vdOparatorCheck(u8* App_u8PressedValueChecked, s32* App_s8OperatorAssign1Checked, s32* App_s8OperatorAssign2Checked, u8* App_u8OperandSendingTimesChecked, u8* App_u8OperatorSendingTimesChecked )
{
	if(*App_u8OperandSendingTimesChecked==0)
	{
		switch(*App_u8PressedValueChecked)
			{
				case '+':
					break;
				case '-':
					*App_s8OperatorAssign1Checked= -1;
					break;
				case'*':
					 *App_s8OperatorAssign1Checked=0;
					break;
				case '/':
					*App_s8OperatorAssign1Checked=0;
					break;
				case '%':
					*App_s8OperatorAssign1Checked=0;
					break;
				case ',':
					*App_s8OperatorAssign1Checked=0;
					break;
					//Casting float
			}
	}
	else if(*App_u8OperandSendingTimesChecked>*App_u8OperatorSendingTimesChecked)
	{
		switch(*App_u8PressedValueChecked)
			{
				case '+':
					break;
				case '-':
					*App_s8OperatorAssign2Checked= -1;
					break;
				case'*':
					 *App_s8OperatorAssign2Checked=0;
					break;
				case '/':
					*App_s8OperatorAssign2Checked=0;
					break;
				case '%':
					*App_s8OperatorAssign2Checked=0;
					break;
				case ',':
					*App_s8OperatorAssign2Checked=0;
					break;
					//Casting float
			}
	}
	else
	{}

}

void App_s32OperationChosen(s32* App_u8FirstOperandCheck, s32* App_u8SecondOperandCheck, u8* App_u8OperatorCheck, s32* App_u2ResultOperationptr, u8*alarm)
{
	switch(*App_u8OperatorCheck)
		{
			case '+':
				*App_u2ResultOperationptr = (*App_u8FirstOperandCheck) + (*App_u8SecondOperandCheck);
				break;
			case '-':
				*App_u2ResultOperationptr= (*App_u8FirstOperandCheck) - (*App_u8SecondOperandCheck);
				break;
			case'*':
				*App_u2ResultOperationptr= (*App_u8FirstOperandCheck) * (*App_u8SecondOperandCheck);
				break;
			case '/':
				if(*App_u8SecondOperandCheck==0)
				{
					*alarm =1;
					break;
				}
				*App_u2ResultOperationptr= (*App_u8FirstOperandCheck) / (*App_u8SecondOperandCheck);
				break;
			case '%':
				*App_u2ResultOperationptr= (*App_u8FirstOperandCheck) % (*App_u8SecondOperandCheck);
				break;
		}

}
