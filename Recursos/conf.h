#ifndef CONF_H
#define CONF_H 1

#include "avr_api.h"

typedef enum {
  ESPERA = 0,
  CARGAR = 1
}estados_t;


// Funcion de inicializacion y configuracion del Micro Controlador
void init_mcu(void);
//lee el valor del sensor de nivel
int leer_nivel(void);
// Estados FSM
estados_t f_espera(void);
estados_t f_cargar(void);


// Definiciones de puertos para el Relay
#define RELE_PORT avr_GPIO_C
#define RELE_PIN  avr_GPIO_PIN_0
#define RELE  avr_GPIOC_OUT_0

// Definiciones de puertos para el LED
#define LED_PORT avr_GPIO_C
#define LED_PIN  avr_GPIO_PIN_1
#define LED  avr_GPIOC_OUT_1

// Canal de conversion para el GP2D12
#define GP2D12 avr_ADC_canal0

// Configuracion de nivel
#define NIVEL_SET 50
#define NIVEL_OFFSET 20




#endif