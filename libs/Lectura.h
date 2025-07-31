#ifndef LECTURA_H
#define LECTURA_H

struct Lectura 
{
    char tipoSensor;    // 'T', 'P', 'E', 'O'
    double valor;       // Valor de la medición del sensor (8 bytes)
};

#endif
