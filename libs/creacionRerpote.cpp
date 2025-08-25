#include <fstream>
#include <iostream>
#include <cstring>
//#include <mutex>
#include <sstream>

//#include "Reporte.h"
#include "Config.h"
#include "Reporte.h"
#include "SalaUCI.h"

struct FechaR {
    int dia;
    int mes;
    int anio;
    int hora;
    int minuto;
    int segundo;
};

using namespace std;

int temp;
int contador=0; 

/*
void copychar(char *d, const char *ori, int tam)
{
    for(int i=0;i<tam;i++)
    {
        d[i]=ori[i];
    }
    
}
*/

void copychar(char *d, const char *ori, int tam) {
    memcpy(d, ori, tam);
    d[tam] = '\0';           
}

int  compararChar(const char *a, const char *b, int tam)
{
    for (int i=0; i<tam;i++)
        {
             if (a[i]!=b[i])
                 { 
                    return 0;
                  };
            if (a[i] == '\0' || b[i] == '\0') { return 1;}
         }
    return 1; 
}

int Rango(double val, Configuracion *conf, char Tipo)
{  
   for (int j = 0; j < 5; j++) 
    {
        if (conf[j].tipoSensor == Tipo)
        {
            if (val < conf[j].min || val > conf[j].max)
            {
                // Devolvemos el índice 'j' donde encontramos la anomalía.
                return j;
            }
        }
    }
    // Si no se encuentra anomalía, devolvemos 9.
    return 9;
}

void imprimirR(ReporteText *rr)
{ for (int i =0; i<10; i++)
    cout << rr[i].RidPac << " " << rr[i].Rfecha << " " << rr[i].RtipoSensor << "  " 
         << rr[i].RValorMed << "  " << rr[i].Rresultado <<"\n";
}



FechaR parsearFechaR(const string& fechaStr) {
    FechaR f;
    char sep; // para leer los caracteres separadores (/, :, espacio)
    
    istringstream ss(fechaStr);
    ss >> f.dia >> sep >> f.mes >> sep >> f.anio;
    ss >> sep; // lee el espacio entre fecha y hora
    ss >> f.hora >> sep >> f.minuto >> sep >> f.segundo;
    
    return f;
}

//Función para comparar fechas

bool compararFechas(char *fecha1, char* fecha2) 
{
    //string fechaTexto = "04/08/2025 15:30:45";
    FechaR f1 = parsearFechaR(fecha1);
    FechaR f2 = parsearFechaR(fecha2);

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

void ordenarPorTipo(ReporteText *repord)
{
    ReporteText tempR;

    for (int i=0;i<contador;i++ )
    {
        for (int j=i+1; j<contador;j++)
        {
          if (repord[i].RtipoSensor > repord[j].RtipoSensor) 
          { 
            tempR = repord[i];
            repord[i]=repord[j];
            repord[j]=tempR;
          }
       }
    }
}

void ordenar(ReporteText *repord)
{
    ReporteText tempR;

    for (int i=0;i<contador;i++ )
    {
        for (int j=i+1; j<contador;j++)
        {
          if (compararFechas(repord[i].Rfecha, repord[j].Rfecha) == true)
          { 
            tempR = repord[i];
            repord[i]=repord[j];
            repord[j]=tempR;
          }
       }
    }
}


void llenarArchivoTXT(ReporteText *rep)
{   cout << "Creando reporte" << "  " << contador << " \n";  
    ofstream TXTreporte("Reporte.txt");

    if(!TXTreporte)
    {
        cout << "No se pudo crear el archivo \n";
    }

    char *fcor = new char [10];
    char *fcorDos = new char [10];

    
    copychar(fcor, rep[0].Rfecha,  10);
    double acum = 0;
    int cc = 0;

    TXTreporte << "----------------------------------------------------------------\n";
    TXTreporte << "Id Paciente | Fecha | Tipo Sensor | Valor Medicion | Resultados \n";
    TXTreporte << "----------------------------------------------------------------\n";

    //fcorDos = fcor; 
    copychar(fcorDos, fcor, 10);

    double minimo;
    double maximo;

    minimo = rep[0].RValorMed;
    maximo = rep[0].RValorMed;

    for (int i=0; i<contador; ++i)    
    {      
        if(strncmp(fcor, fcorDos, 10) == 0)
        {
            if(minimo > rep[i].RValorMed)
            {
                minimo = rep[i].RValorMed;
            };

            if(maximo < rep[i].RValorMed)
            {
                maximo = rep[i].RValorMed;
            };

            acum = rep[i].RValorMed + acum;
            cc ++;
            copychar(fcorDos, rep[i].Rfecha, 10);
            
        } else {
            double prom = acum / cc;
            
            TXTreporte << "----------------------------------------------------------------\n";
            TXTreporte << "        PROMEDIO    " << prom << " Maximo: " << maximo <<" minimo " << minimo<< "\n"; 
            TXTreporte << "----------------------------------------------------------------\n";
            
            minimo = rep[i].RValorMed;
            maximo = rep[i].RValorMed;
            
            acum = 0;
            cc = 1;
            copychar(fcor, rep[i].Rfecha, 10);

        }    

        TXTreporte << rep[i].RidPac <<"  |  " << rep[i].Rfecha << "  | " << rep[i].RtipoSensor << "  |  " << rep[i].RValorMed << "  | " << rep[i].Rresultado << "\n";
        
        
    };
    if (cc > 0) 
    {
        double prom = acum / cc;
        TXTreporte << "----------------------------------------------------------------\n";
        TXTreporte << "        PROMEDIO      " << prom << " Maximo: " << maximo <<" minimo " << minimo<< "\n"; 
        TXTreporte << "----------------------------------------------------------------\n";
    }
    
    
    
}

void completarReporte(ReporteText *rep)
{
      //imprimirR(rep);
      cout << "Ordenando reporte.........por fecha" << "\n";
      ordenar(rep); // ordenar por fecha
      //ordenarPorTipo(rep); // ordenar por Tipo de Sensor
      llenarArchivoTXT(rep);
}

//Función para llenar la estructura de un reporte

void llenarEstructReporte(SalaUCI salauci, ReporteText *report, const char id[11], Configuracion *conf)
{
     // contador de registros para el archivo de texto.
    for(int i = 0; i < static_cast<int>(salauci.numMaquinas); i ++)
    {   
        if(salauci.maquinas[i].numMediciones <= 0) continue;
        
        for (int r = 0; r < salauci.maquinas[i].numMediciones; r++)
        {  
            int p=compararChar(id,salauci.maquinas[i].mediciones->idPaciente,11);
            if(p==1)  //Validación para saber si la ID es correcta.
            {   
               for(int a = 0; a < salauci.maquinas[i].mediciones[r].numLecturas; a++)
                {
                   double tempVal = salauci.maquinas[i].mediciones[r].lecturas[a].valor; 
                   char tempTipo = salauci.maquinas[i].mediciones[r].lecturas[a].tipoSensor;
                
                   char resultado[10];
                   if(salauci.maquinas[i].mediciones[r].lecturas[a].tipoSensor != 'E')
                    {
                        temp = Rango(tempVal, conf, tempTipo);
                        
                        if(temp != 9)
                        {   
                            strcpy(resultado,"Anomalía");
                           
                        } else 
                           { 
                            strcpy(resultado,"Normal");
                           }

                    }else {
                        strcpy(resultado, " ");
                    }
                    
                        
                        //Pasar datpos a la estructura temporal de repor
                        copychar(report[contador].RidPac,id,11);
                        copychar(report[contador].Rfecha,salauci.maquinas[i].mediciones[r].fechaHora,24);
                        report[contador].RtipoSensor=tempTipo;
                        report[contador].RValorMed=tempVal;
                        copychar(report[contador].Rresultado,resultado,10);
                    
                        contador++; //Numero de registros pasados al struct reporte
                }
            }
        }
    }   
    completarReporte(report);
}

void calcular(SalaUCI sala, ReporteText *&reporte,  const char id[11],Configuracion *config)
{
    llenarEstructReporte(sala, reporte, id, config);
}