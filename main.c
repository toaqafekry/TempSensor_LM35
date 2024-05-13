/*
 * main.c
 *
 *  Created on: Apr 5, 2024
 *      Author: Toa Fekry
 */



#include <util/delay.h>
#include "MCAL/DIO/Header/DIO_Interface.h"
#include "HAL/LED/Header/Led_Interface.h"
#include "MCAL/ADC/Header/ADC_Interface.h"

void main()
{
	DIO_SetDirectionForPin(DIO_GroupA,DIO_Pin0,DIO_Input);
	DIO_SetDirectionForPin(DIO_GroupC,DIO_Pin0,DIO_Output);
	DIO_SetDirectionForPin(DIO_GroupC,DIO_Pin1,DIO_Output);
	DIO_SetDirectionForPin(DIO_GroupC,DIO_Pin2,DIO_Output);

	ADC_Init(3);  //8prescaler//

	u16 Digtal_Volt=0;
	u16 Analog_Volt=0;
	u16 Temp_Value=0;

	while(1)
	{
		Digtal_Volt=ADC_GetDigitalValue(0);                 // 3SHN COMILER MYTLGHBSH//
		Analog_Volt=((u32)Digtal_Volt*5000UL)/1024UL;  //U32 CASR 3SHN MUNF3SH U16*U32// //UL 3SHN Y7DD RKM
		Temp_Value= Analog_Volt/10;

		if(Temp_Value<=25)
		{
			DIO_SetOutputForPin(DIO_GroupC,DIO_Pin0,1);
			DIO_SetOutputForPin(DIO_GroupC,DIO_Pin1,0);
			DIO_SetOutputForPin(DIO_GroupC,DIO_Pin2,0);

		}
		else if (Temp_Value>25 && Temp_Value<=40)
		{
			DIO_SetOutputForPin(DIO_GroupC,DIO_Pin0,0);
			DIO_SetOutputForPin(DIO_GroupC,DIO_Pin1,1);
			DIO_SetOutputForPin(DIO_GroupC,DIO_Pin2,0);
		}
		else if (Temp_Value>40)
		{
			DIO_SetOutputForPin(DIO_GroupC,DIO_Pin0,0);
			DIO_SetOutputForPin(DIO_GroupC,DIO_Pin1,0);
			DIO_SetOutputForPin(DIO_GroupC,DIO_Pin2,1);
		}

	}
}







