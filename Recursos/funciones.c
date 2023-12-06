#include "conf.h"

void init_mcu(void){
   GpioInitStructure_AVR rele, led;
   AdcInitStructure_AVR GP2D12;
   
   rele.port = RELE_PORT;
   rele.pines = RELE_PIN;
   rele.modo = avr_GPIO_mode_Output;
   init_gpio(rele);
   
   led.port = LED_PORT;
   led.pines = LED_PIN;
   led.modo = avr_GPIO_mode_Output;
   init_gpio(led);
   
   GP2D12.mode = avr_ADC_MODE_Single_Conversion;
   GP2D12.reference = avr_ADC_REF_Internal ;
   GP2D12.resolution = avr_ADC_RES_10Bit;
   /*GP2D12.channel = GP2D12;*/
   GP2D12.prescaler = avr_ADC_Prescaler_64;
   init_adc(GP2D12);
   
   RELE = 0;
   

}

// lectura del adc 0 - 1023 => (2350/1024) = 2.3 cuentas por milivolt | 2.3* cuentas = milivolts leidos | 23mv = 1cm
int leer_nivel(void){
   return (((float)leer_ADC(GP2D12) * (2350.0/1024.0)/18.0));
}

