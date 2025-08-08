#include <string>
#include <fstream>
#include "Config.h"
//#include "libs/Separar_Pacientes.cpp"

using namespace std;
void configAStruct(char** data, Configuracion& config )
{
    config.tipoSensor = *data[0];
    config.min = stod(data[1]);
    config.max = stod(data[2]);

}

void cargarConfiguracion(const string& archivo) 
{
    ifstream file(archivo);
    string linea;
    Configuracion config;
    
    while (getline(file, linea)) 
    {
        //configAStruct(separar(linea, 3, ','), config);
        // Almacenar la configuración en una estructura o hacer algo con ella
    }
}
