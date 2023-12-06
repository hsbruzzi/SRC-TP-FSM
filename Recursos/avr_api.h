#ifndef AVR_API_H_
#define AVR_API_H_
/***********************************************************************************************/
//inclusiones generales.
#include <avr/io.h>
#include <avr/interrupt.h>
/***********************************************************************************************/
/***********************************************************************************************/
// Macro y variable General para manejo de a bit.
typedef struct
	{
	unsigned char B0:1;
	unsigned char B1:1;
	unsigned char B2:1;
	unsigned char B3:1;
	unsigned char B4:1;
	unsigned char B5:1;
	unsigned char B6:1;
	unsigned char B7:1;
	}bit_t;

#define REGBIT(reg,bt)	((volatile bit_t*)&reg)->B##bt	//MACRO PARA MANEJAR REGISTROS DE A BIT.
/***********************************************************************************************/
/***********************************************************************************************/
// Librerias de perifericos. Comentar la que no se use.
#include "avr_Extint.h"	    //Libreria para Interrupciones Externas
#include "avr_Timers.h"		//Libreria para control de Timers
#include "avr_Adc.h"		//Librerias ADC
#include "avr_Spi.h"		//Librerias SPI
#include "avr_Uart.h"		//Librerias UART
#include "avr_Gpio.h"		//Librerias para puertos de proposito general.
/***********************************************************************************************/


#endif /* AVR_API_H_ */
