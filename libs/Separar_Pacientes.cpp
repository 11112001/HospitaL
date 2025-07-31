//Nuevo Código.
#include <iostream>
#include <fstream>
#include <sstream>

#include "Paciente.h"

using namespace std;

void separarPaciente(const string& linea, Paciente& paciente) 
{
    stringstream ss(linea);
    char delimiter = ';';
    ss >> paciente.id >> paciente.tipoDeDocumento >> paciente.documento
       >> paciente.nombres >> paciente.apellidos >> paciente.fechaNacimiento
       >> paciente.telefono >> paciente.email >> paciente.tipoDeSangre
       >> paciente.entidadSalud >> paciente.medicinaPrepagada;
}

void cargarPacientes(const string& archivo) 
{
    ifstream file(archivo);
    string linea;
    while (getline(file, linea)) {
        Paciente paciente;
        separarPaciente(linea, paciente);
        // Almacenar los datos del paciente o procesarlos
    }
}
