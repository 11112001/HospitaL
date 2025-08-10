//#include "Config.h"
#include "Lectura.h"
#include "MaquinaUCI.h"
#include "Medicion.h"
#include "SalaUCI.h"
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

void leerDato(ifstream& ar, void* destino, size_t tama) 
{
    ar.read(reinterpret_cast<char*>(destino), tama);
}

SalaUCI leerEstructuraBinaria(string Ruta)
{
    
    ifstream archivo(Ruta, ios::binary);

    if(!archivo)
    {
        cerr << "Error al abrir el archivo / Archivo no encontrado" << "\n";
        exit(1);
    }

    SalaUCI sala;

    leerDato(archivo, &sala.idSala, sizeof(sala.idSala));
    leerDato(archivo, &sala.numMaquinas, sizeof(sala.numMaquinas));

    sala.idSala = sala.idSala;
    sala.numMaquinas = sala.numMaquinas;

    cout << "Sala: " << static_cast<int>(sala.idSala) << "\n";
    cout << "Numero Maquinas: " << static_cast<int>(sala.numMaquinas) << "\n";

    //Si sala.num_maquinas es mayor que 0, reservar un arreglo dinámico de Maquina de ese tamaño; si no, poner el puntero a nullptr
    sala.maquinas = (sala.numMaquinas ? new MaquinaUCI[sala.numMaquinas] : nullptr);

    int numero_Maquinas = static_cast<int>(sala.numMaquinas);
    for(int i = 0; i < numero_Maquinas; ++i)
    { 
        
        MaquinaUCI& maq = sala.maquinas[i];

        leerDato(archivo, &maq.idMaquina, sizeof(maq.idMaquina));
        leerDato(archivo, &maq.numMediciones, sizeof(maq.numMediciones));
        
        sala.maquinas[i].idMaquina = static_cast<int>(maq.idMaquina);
        sala.maquinas[i].numMediciones = maq.numMediciones;

        cout << "Sala xx: " << static_cast<int>(maq.idMaquina) << "\n";
        cout << "Numero Mediciones Xx" << sala.maquinas[i].numMediciones << "\n";

        //Leer valores desde el binario
        cout << "\n--- Máquina " << (i+1) << " ---\n";
        cout << "ID Maquina: " << static_cast<int>(sala.maquinas[i].idMaquina) << "\n";
        cout << "Número de mediciones: " << maq.numMediciones << "\n";
        cout << "\n --------------- \n";
        
        
        maq.mediciones = (maq.numMediciones ? new Medicion[maq.numMediciones] : nullptr);    
        
        for(int m = 0; m < maq.numMediciones; ++m )
        {
            Medicion& med = maq.mediciones[m];            
            
            leerDato(archivo, &med.idPaciente, 11);
            leerDato(archivo, &med.fechaHora, 24);
            leerDato(archivo, &med.numLecturas, 4);
            
            strcpy(sala.maquinas[i].mediciones[m].idPaciente, med.idPaciente);
            strcpy(sala.maquinas[i].mediciones[m].fechaHora, med.fechaHora);
            sala.maquinas[i].mediciones[m].numLecturas = med.numLecturas;
            
            cout << "Id paciente Xx " << sala.maquinas[i].mediciones[m].idPaciente << "\n";
            cout << "Fecha Hora Xx " << sala.maquinas[i].mediciones[m].fechaHora << "\n";
            cout << "Mediciones Xx " << sala.maquinas[i].mediciones[m].numLecturas << "\n";

            cout << "\n  >> Medición " << (m+1) << "\n";
            cout << "  ID Paciente: " << med.idPaciente << "\n";
            cout << "  Fecha y hora: " << med.fechaHora << "\n";
            cout << "  Número de lecturas: " << med.numLecturas << "\n";
            
            med.lecturas = (med.numLecturas ? new Lectura[med.numLecturas] : nullptr);

            for (int r = 0; r < med.numLecturas; ++r)
            {
                Lectura& L = med.lecturas[r];
                leerDato(archivo, &L.tipoSensor, 1);
                sala.maquinas[i].mediciones[m].lecturas[r].tipoSensor = L.tipoSensor;
                
                cout <<"tipo Sensor Xx " << sala.maquinas[i].mediciones[m].lecturas[r].tipoSensor << "\n";

                char dato[8];
                if(L.tipoSensor == 'P')
                {
                    leerDato(archivo, dato, 8);    
                }else {   
                    leerDato(archivo, &L.valor, sizeof(L.valor));
                }


                sala.maquinas[i].mediciones[m].lecturas[r].valor = L.valor;

                cout <<"Valor xx " << sala.maquinas[i].mediciones[m].lecturas[r].valor << "\n";

                cout << "  Lectura " << (r + 1) << "\n";
                cout << "  Tipo: " << L.tipoSensor << "\n";
                if(L.tipoSensor == 'P')
                {
                    cout << "  Valor: " << dato << "\n";    
                }else {
                    cout << "  Valor: " << L.valor << "\n";
                }
            }
            //memset(&maq, 0, sizeof(maq));
        }
    }

    //cout << "Sala dentro de leer binario: " << static_cast<int>(sala.maquinas[0].idMaquina) << "\n";
    //cout << "otro dato: " << sala.maquinas[0].mediciones[0].numLecturas <<"\n";
    return sala;
}
//
