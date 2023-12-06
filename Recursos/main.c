#include "conf.h"


int main()
 { 
   estados_t estado=ESPERA;
    estados_t (*fsm[2])(void) = {f_espera,f_cargar}; 
   init_mcu();
  while (1) {   
      switch(estado){
	 case ESPERA:
	    estado = f_espera();
	    break;      
	 case CARGAR:
	    estado = f_cargar();
	    break;
      }     
   }
   
  while(1) estado = (*fsm[estado])();  
   
   return 0;
 }