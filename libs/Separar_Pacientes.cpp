//Nuevo Código.
//#include <iostream>
//#include <fstream>
#include <sstream>
#include <string>
#include <cstring>

#include "Paciente.h"


using namespace std;

/*
void separarPaciente(const string& linea, Paciente& paciente) 
{
    stringstream ss(linea);
    char delimiter = ';';
    ss >> paciente.id >> paciente.tipoDeDocumento >> paciente.documento
    >> paciente.nombres >> paciente.apellidos >> paciente.fechaNacimiento
    >> paciente.telefono >> paciente.email >> paciente.tipoDeSangre
    >> paciente.entidadSalud >> paciente.medicinaPrepagada;
}
*/

void cadAStruct(char** datos, Paciente& paciente)
{
    paciente.id = atoi(datos[0]);
    
    strcpy(paciente.tipoDeDocumento, datos[1]);
    strcpy(paciente.nombres, datos[2]);
    strcpy(paciente.nombres, datos[3]);
    strcpy(paciente.apellidos, datos[4]);
    strcpy(paciente.fechaNacimiento, datos[5]);
    strcpy(paciente.telefono, datos[6]);
    strcpy(paciente.email, datos[7]);
    strcpy(paciente.tipoDeSangre, datos[8]);
    strcpy(paciente.entidadSalud, datos[9]);
    strcpy(paciente.medicinaPrepagada, datos[10]);
} 


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
char* separarPaciente(const string& linea, Paciente& paciente)
{
    char ** temp = new char*[11];
    stringstream ss(linea);
    string token;

    for(int i = 0; i <11; i++)
    {
        getline(ss, token, ';');
        strcpy(temp[i], cadenaAChar(token));
    }

    return *temp;
}

/*
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
*/

struct Fecha {
    int dia;
    int mes;
    int anio;
    int hora;
    int minuto;
    int segundo;
};

Fecha parsearFecha(const string& fechaStr) {
    Fecha f;
    char sep; // para leer los caracteres separadores (/, :, espacio)
    
    istringstream ss(fechaStr);
    ss >> f.dia >> sep >> f.mes >> sep >> f.anio;
    ss >> sep; // lee el espacio entre fecha y hora
    ss >> f.hora >> sep >> f.minuto >> sep >> f.segundo;
    
    return f;
}

bool compararFechas(string fecha1, string fecha2) 
{
    //string fechaTexto = "04/08/2025 15:30:45";
    Fecha f1 = parsearFecha(fecha1);
    Fecha f2 = parsearFecha(fecha2);

    if(f1.anio > f2.anio)
    {
        return true;
    }else if(f1.anio != f2.anio){
        return false;
    }else if(f1.mes > f2.mes) {
        return true;
    }else if(f1.mes != f2.mes){
        return false;
    }else if(f1.dia > f2.dia){
        return true;
    }else if(f1.dia != f2.dia){
        return false;
    }else if(f1.hora > f2.hora){
        return true;
    }else if(f1.hora != f2.hora){
        return false;
    }else if(f1.minuto > f2.minuto){
        return true;
    }else if (f1.minuto != f2.minuto){
        return false;
    }else if(f1.segundo > f2.segundo){
        return true;
    }else if(f1.segundo != f2.segundo){
        return false;
    }else{
        return true; // atp. som iguales, pero se toma cualquiera los dos como mayor.
    }
}
