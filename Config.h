#ifndef CONFIG_H
#define CONFIG_H

struct Configuracion 
{
    char tipoSensor;    // 'T', 'P', 'E', 'O'
    double min;         // Umbral mínimo
    double max;         // Umbral máximo
};

#endif
