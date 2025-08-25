#ifndef LECTURA_H
#define LECTURA_H

struct Lectura 
{
    /*
        está mal lmao.
        arreglo double dos pos tipo sensor
    */

    char tipoSensor;    // 'T', 'P', 'E', 'O'
    double valor;       // Valor de la medición del sensor (8 bytes) 

    //El valor debe ser un arreglo de dos posiciones para P (sis dia)
};

#endif