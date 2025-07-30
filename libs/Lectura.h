#ifndef LECTURA_H
#define LECTURA_H

#include <string>

const int MAX_PACIENTES = 1000;  
const int MAX_REGISTROS = 100;   


struct Paciente {
    char id[20];
    char nombre[50];
    char fechaNacimiento[15];
    char genero[10];
    char registros[MAX_REGISTROS][100];  
    int totalRegistros = 0;
};



int leerArchivoBSF(const char* rutaArchivo, Paciente pacientes[], int maxPacientes);


bool validarFormatoBSF(const char* linea);


void mostrarPacientes(const Paciente pacientes[], int cantidad);

#endif 