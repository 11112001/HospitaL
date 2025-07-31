//Código nuevo
#include <iostream>
#include <fstream>
#include <sstream>
#include "Config.h"

using namespace std;

void separarConfiguracion(const string& linea, Configuracion& config) 
{
    stringstream ss(linea);
    ss >> config.tipoSensor >> config.min >> config.max;
}

void cargarConfiguracion(const string& archivo) 
{
    ifstream file(archivo);
    string linea;
    while (getline(file, linea)) 
    {
        Configuracion config;
        separarConfiguracion(linea, config);
        // Almacenar la configuración en una estructura o hacer algo con ella
    }
}

