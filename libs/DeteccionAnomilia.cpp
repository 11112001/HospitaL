#include "Config.h"
#include "Medicion.h"
#include "MaquinaUCI.h"
#include "SalaUCI.h"
//#include <cstdlib>
#include <iostream>

using namespace std;

int estaEnRango(double val, Configuracion *Confi, char Tipo)
{  
    /*
    for (int i = 0; i < 5; i++ ) 
    {
        cout << Confi[i].tipoSensor <<","<<Confi[i].min << "," << Confi[i].max << "" <<"\n";
    };
    */

    for (int i = 0; i < 5; i++ ) 
    {
        if(Confi[i].tipoSensor == Tipo )
        {
            if(val < Confi[i].min || val > Confi[i].max)
            {
                return i;
            };
        }
    }
    return 9;
}

bool deteccionAnomala(const char *idPac, SalaUCI sal, Configuracion *conf)
{
    int temp;

    for(int i = 0; i < static_cast<int>(sal.numMaquinas); i ++)
    {
        for (int r = 0; r < sal.maquinas[i].numMediciones; r++)
        {
            for(int a = 0; a < sal.maquinas[i].mediciones[r].numLecturas; a++)
            {
                cout << sal.maquinas[i].mediciones[r].lecturas[a].tipoSensor << "\n";
                
                if(sal.maquinas[i].mediciones[r].lecturas[a].tipoSensor != 'E')
                {
                    temp = estaEnRango(sal.maquinas[i].mediciones[r].lecturas[a].valor, conf, sal.maquinas[i].mediciones[r].lecturas[a].tipoSensor);
                    
                    if(temp != 9)
                    {
                        cout << "El paciente con id: " << sal.maquinas[i].mediciones[r].idPaciente << " tiene una anomalía en: " 
                             <<  sal.maquinas[i].mediciones[r].lecturas[a].tipoSensor << " con el valor de: " << sal.maquinas[i].mediciones[r].lecturas[a].valor
                             << " en el rango limite máximo de: " << conf[i].max << " y rango minimo de: " << conf[i].min;
                        }
                }
            }
        }
    }
    return 0;
}