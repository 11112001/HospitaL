//Nuevo Código.
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <fstream>

#include "Config.h"
#include "Paciente.h"


using namespace std;

//función para pasar los datos de un paciente a la estructura de paciente

void pacAStruct(char** datos, Paciente& paciente)
{
    paciente.id = atoi(datos[0]);
    
    strcpy(paciente.tipoDeDocumento, datos[1]);
    strcpy(paciente.documento, datos[2]);
    strcpy(paciente.nombres, datos[3]);
    strcpy(paciente.apellidos, datos[4]);
    strcpy(paciente.fechaNacimiento, datos[5]);
    strcpy(paciente.telefono, datos[6]);
    strcpy(paciente.email, datos[7]);
    strcpy(paciente.tipoDeSangre, datos[8]);
    strcpy(paciente.entidadSalud, datos[9]);
    strcpy(paciente.medicinaPrepagada, datos[10]);
} 

//Función para pasar cadenas a chars

char* cadenaAChar(const string& str) 
{
    char* arr = new char[str.size() + 1];
    for (size_t i = 0; i < str.size(); ++i) {
        arr[i] = str[i];
    }
    arr[str.size()] = '\0';  
    return arr;
}

//una sola linea
char** separar(const string& linea, int cantidad, char delimitador)
{
    char ** temp = new char*[cantidad];
    stringstream ss(linea);
    string token;

    for(int i = 0; i <cantidad; i++)
    {
        getline(ss, token, delimitador);
        //strcpy(temp[i], cadenaAChar(token));
        temp[i] = cadenaAChar(token);
    }

    return temp;
}

//Función para imprimir una estructura

void imprimirEstruct(Paciente*& paciente)
{
    cout << "--------PACIENTES:----------\n";
    cout << "ID | TDoc| Doc | Nombre | Ape | Nac | Tele | Email | Sangre | EPS | MedPre\n";
    cout << "-------------------------------\n";
    for (int i = 0; i < 20; i ++)
    {
        cout << paciente[i].id << paciente[i].tipoDeDocumento << paciente[i].nombres << paciente[i].apellidos << paciente[i].fechaNacimiento << paciente[i].telefono << paciente[i].email << paciente[i].tipoDeDocumento << paciente[i].entidadSalud << paciente[i].medicinaPrepagada << "\n";   
    }    
    cout << "-------------------------------\n";
}

void cargarPacientes(const string& archivo) 
{
    ifstream archi(archivo);

    
    if(!archi)
    {
        cout <<"Archivo no encontrado";
        exit(0);
    }
    
    
    string linea;
    Paciente *paciente = new Paciente[100];
    int cont = 0;
    while (getline(archi, linea)) {
        
        pacAStruct(separar(linea, 11, ';'), paciente[cont]);
        // Almacenar los datos del paciente o procesarlos
        cont ++;
    }

    imprimirEstruct(paciente);
}
