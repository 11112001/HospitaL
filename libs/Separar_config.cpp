//Código nuevo
//#include <fstream>
//#include <iostream>
#include <cstddef>
#include <cstring>
#include <sstream>
#include <cstring>
#include <string>

#include "Config.h"

using namespace std;

char* StringAChar(const string& str) 
{
    char* arr = new char[str.size() + 1];
    for (size_t i = 0; i < str.size(); ++i) {
        arr[i] = str[i];
    }
    arr[str.size()] = '\0';  
    return arr;
}

//una sola linea
char** separarConfiguracion(string linea) 
{
    //Creación de matríz
    char** temp = new char *[3];
    if (linea.empty() || linea[0] == '#') return NULL;

    stringstream ss(linea);
    string tipo;
    string minStr, maxStr;

    getline(ss, tipo, ',');
    getline(ss, minStr, ',');
    getline(ss, maxStr, ',');

    temp[0] = StringAChar(tipo);
    temp[1] = StringAChar(minStr);
    temp[2] = StringAChar(maxStr);

    
    
    return temp;
}

void configAStruct(char** datos, Configuracion& config )
{
    config.tipoSensor = *datos[0];
    config.min = stod(datos[1]);
    config.max = stod(datos[2]);
    
}
//Leer archivo lmao

/*
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
*/

