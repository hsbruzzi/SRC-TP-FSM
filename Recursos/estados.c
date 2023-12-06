#include "conf.h"

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
}
