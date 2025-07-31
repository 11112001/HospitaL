#ifndef SALA_UCI_H
#define SALA_UCI_H

#include "MaquinaUCI.h"

struct SalaUCI 
{
    char idSala;                 // ID de la sala de UCI (1 byte)
    int numMaquinas;             // Número de máquinas en la sala
    MaquinaUCI* maquinas;        // Arreglo dinámico de máquinas
};

#endif
