#include "conf.h"

<<<<<<< HEAD
estados_t f_espera(void) {
    int nivel;
    nivel = leer_nivel();

    // Apaga RELE y LED en estado de espera
    RELE = 0;
    LED = 0;

    if (nivel >= (NIVEL_SET + NIVEL_OFFSET)) {
        // Transición al estado de carga si se cumple la condición
        return CARGAR;
    } else {
        // Permanece en estado de espera
        return ESPERA;
    }
}

estados_t f_cargar(void) {
    int nivel;
    nivel = leer_nivel();

    // Enciende RELE y LED en estado de carga
    RELE = 1;
    LED = 1;

    if (nivel <= (NIVEL_SET - NIVEL_OFFSET)) {
        // Transición al estado de espera si se cumple la condición
        return ESPERA;
    } else {
        // Permanece en estado de carga
        return CARGAR;
    }
=======
estados_t f_espera(void){
   int nivel;
   nivel = leer_nivel();
   if(nivel <= (NIVEL_SET - NIVEL_OFFSET) ) {
      RELE = 1; // Activa RELE en estado de carga
      LED = 1;
      return CARGAR;
   }
   else {
      RELE = 0; // Apaga RELE en estado de espera
      LED = 0;
      return ESPERA;
   }
}

estados_t f_cargar(void){
   int nivel;
   nivel = leer_nivel();
   if(nivel >= (NIVEL_SET + NIVEL_OFFSET) ) {
       RELE = 0;
       LED = 0;
      return ESPERA;
   } else {
      RELE = 1;
      LED = 1;
      return CARGAR;
   }
>>>>>>> 4f2be87fdcb8825d1e883a11f9f979f864f65f2e
}
