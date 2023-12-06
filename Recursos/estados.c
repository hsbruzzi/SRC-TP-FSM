
#include "conf.h"

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
}
