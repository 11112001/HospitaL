#include "Config.h"
#include "Medicion.h"
#include "MaquinaUCI.h"
#include "SalaUCI.h"
//#include <cstddef>
#include <iostream>
//#include <iterator>


using namespace std;

int estaEnRango(double val, Configuracion *conf, char Tipo)
{  

    for (int j = 0; j < 5; j++) 
    {
        if (conf[j].tipoSensor == Tipo)
        {
            if (val < conf[j].min || val > conf[j].max)
            {
                return j;
            }
        }
    }
    return 9;
}

/*
void imprimirConfiguracion(Configuracion*& config)
{
    for (int i = 0; i < 5; i ++)
    {
        cout <<"Tipo Sensor: " << config[i].tipoSensor << "\n";
        cout <<"Minimo " << config[i].min << "\n";
    }
}
*/

void imprimirConfiguracion(Configuracion*& config)
{
    Configuracion* p = config;

    while(p->tipoSensor != '0')
    {
        cout << "Tipo de sensor: " << p -> tipoSensor << "\n";
        cout << "Mínimo: " << p -> min << "\n";
        ++p;
    }

}



//Función para detectar anomalía. 

bool deteccionAnomala(const char *idPac, SalaUCI sal, Configuracion*& conf)
{
    int temp;

    for(int i = 0; i < static_cast<int>(sal.numMaquinas); i ++)
    {
        if(sal.maquinas[i].numMediciones <= 0) continue;
        
        for (int r = 0; r < sal.maquinas[i].numMediciones; r++)
        {
            int k = compararChar(idPac, sal.maquinas[i].mediciones->idPaciente, 11);
            if(k == 1)  //Validación para saber si la ID es correcta. 
            {   
                for(int a = 0; a < sal.maquinas[i].mediciones[r].numLecturas; a++)
                {                    
                    if(sal.maquinas[i].mediciones[r].lecturas[a].tipoSensor != 'E')
                    {
                        double tempVal = sal.maquinas[i].mediciones[r].lecturas[a].valor; 
                        char tempTipo = sal.maquinas[i].mediciones[r].lecturas[a].tipoSensor;
                        
                        temp = estaEnRango(tempVal, conf,tempTipo);
                        
                        if(temp != 9)
                        {
                            cout << "--------------------------------------------------\n";
                            cout << "El paciente con id: " << sal.maquinas[i].mediciones[r].idPaciente << " tiene una anomalía en: " 
                            <<  sal.maquinas[i].mediciones[r].lecturas[a].tipoSensor << " con el valor de: " << sal.maquinas[i].mediciones[r].lecturas[a].valor
                            << " en el rango limite máximo de: " << conf[temp].max << " y rango minimo de: " << conf[temp].min << "\n";
                            cout << "--------------------------------------------------\n";                          
                        }
                    }
                }
            }
        }
    }
        return 0;
}