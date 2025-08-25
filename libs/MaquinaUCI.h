#ifndef MAQUINA_UCI_H
#define MAQUINA_UCI_H

#include "Medicion.h"

struct MaquinaUCI 
{
    char idMaquina;             // ID de la máquina (1 byte)
    int numMediciones;          // Número de mediciones que realiza
    Medicion* mediciones; // Arreglo dinámico de mediciones
};

#endif  
