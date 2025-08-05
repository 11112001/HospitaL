#ifndef PACIENTE_H
#define PACIENTE_H

struct Paciente 
{
    int id;
    char tipoDeDocumento[3];  
    char documento[20];       
    char nombres[100];
    char apellidos[100];
    char fechaNacimiento[11]; 
    char telefono[15];
    char email[100];
    char tipoDeSangre[5];
    char entidadSalud[50];
    char medicinaPrepagada[50];
};

#endif
