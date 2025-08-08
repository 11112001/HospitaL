//Nuevo Código.
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <fstream>

#include "Paciente.h"


using namespace std;

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

    //Imprimir
    //cout << "documento: " << paciente.id << "\n";
    //cout << "medicina prepaga: " << paciente.medicinaPrepagada << "\n";
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

void imprimirEstruct(Paciente*& paciente)
{
    for (int i = 0; i < 3; i ++)
    {
        cout <<"id: " << paciente[i].id << "\n";
        cout <<"Medicina prepagada: " << paciente[i].medicinaPrepagada << "\n";
    }
}

void cargarPacientes(const string& archivo) 
{
    ifstream archi(archivo);

    /*
    if(!archi)
    {
        cout <<"Archivo no encontrado";
        exit(0);
    }
    */
    
    string linea;
    Paciente *paciente = new Paciente[2];
    int cont = 0;
    while (getline(archi, linea)) {
        
        pacAStruct(separar(linea, 11, ';'), paciente[cont]);
        // Almacenar los datos del paciente o procesarlos
        cont ++;
    }
    //imprimirEstruct(paciente);
}



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
