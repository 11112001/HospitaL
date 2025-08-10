#include <cstdlib>
#include <string>
#include <fstream>
#include "Config.h"
#include <iostream>

using namespace std;
void configAStruct(char** data, Configuracion*& config, int cont )
{
    config[cont].tipoSensor = *data[0];
    config[cont].min = stod(data[1]);
    config[cont].max = stod(data[2]);
}

void imprimirEstruct(Configuracion*& config)
{
    for (int i = 0; i < 5; i ++)
    {
        cout <<"Tipo Sensor: " << config[i].tipoSensor << "\n";
        cout <<"Minimo " << config[i].min << "\n";
    }
}

void cargarConfiguracion(const string& archivo, Configuracion*& Config) 
{
    ifstream file(archivo);
    
    if(!file)
    {
        cout << "Error al abrir el archivo" << "\n";
        exit(0);
    }

    string linea;
    Configuracion *configu = new Configuracion[5];
    int contador = 0;
    
    while (getline(file, linea)) 
    {
        configAStruct(separar(linea, 3, ','), configu, contador);
        // Almacenar la configuración en una estructura o hacer algo con ella
        contador ++;
    }
    Config = configu;
    imprimirEstruct(configu);

}



