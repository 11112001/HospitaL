#ifndef MEDICION_H
#define MEDICION_H

#include <string>
#include "Lectura.h"

struct Medicion 
{
    char idPaciente[11];       
    char fechaHora[24];        
    int numLecturas;           
    Lectura* lecturas;   
};

#endif
