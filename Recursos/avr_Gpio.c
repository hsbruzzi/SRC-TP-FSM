#include "avr_Gpio.h"
#include "avr/io.h"


void init_gpio(GpioInitStructure_AVR Gpio) {
	if (Gpio.modo == avr_GPIO_mode_Output) {
		switch (Gpio.port) {
// Los siguientes micros tienen GPIO A
#if defined_AVR_PORTA
		case avr_GPIO_A:
			DDRA |= Gpio.pines;
			break;
#endif
// Los Siguientes micros tienen puerto B
#if defined_AVR_PORTB
		case avr_GPIO_B:
			DDRB |= Gpio.pines;
			break;
#endif
//Los siguientes micros tienen puerto C
#if defined_AVR_PORTC
		case avr_GPIO_C:
			DDRC |= Gpio.pines;
			break;
#endif
// Los siguientes micros tienen Puerto D
#if defined_AVR_PORTD
		case avr_GPIO_D:
			DDRD |= Gpio.pines;
			break;
#endif
#if defined_AVR_PORTE
		case avr_GPIO_E:
			DDRE |= Gpio.pines;
			break;
#endif
#if defined_AVR_PORTF
		case avr_GPIO_F:
			DDRF |= Gpio.pines;
			break;
#endif
#if defined_AVR_PORTG
		case avr_GPIO_G:
			DDRG |= Gpio.pines;
			break;
#endif
		default: break;
		}
	} else {
		switch (Gpio.port) {
#if defined_AVR_PORTA
		case avr_GPIO_A:
			DDRA &= ~Gpio.pines;
			break;
#endif
#if defined_AVR_PORTB
		case avr_GPIO_B:
			DDRB &= ~Gpio.pines;
			break;
#endif
#if defined_AVR_PORTC
		case avr_GPIO_C:
			DDRC &= ~Gpio.pines;
			break;
#endif
#if defined_AVR_PORTD
		case avr_GPIO_D:
			DDRD &= ~Gpio.pines;
			break;
#endif
#if defined_AVR_PORTE
		case avr_GPIO_E:
			DDRE &= ~Gpio.pines;
			break;
#endif
#if defined_AVR_PORTF
		case avr_GPIO_F:
			DDRF &= ~Gpio.pines;
			break;
#endif
#if defined_AVR_PORTG
		case avr_GPIO_G:
			DDRG &= ~Gpio.pines;
			break;
#endif
		default: break;
		}
	}

}


