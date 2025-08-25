#ifndef CONFIG_H
#define CONFIG_H

#include <string>
using namespace std;

struct Configuracion 
{
    char tipoSensor;    // 'T', 'P', 'E', 'O'
    double min;         // Umbral mínimo
    double max;         // Umbral máximo
};

char** separar(const string& linea, int cantidad, char delimitador);
int  compararChar(const char *a, const char *b, int tam);

#endif