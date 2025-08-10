//librerias:
#include <iostream>
#include <unistd.h>
#include <limits.h>

//Por qué da warning!
#include "libs/Config.h"
//#include "libs/MaquinaUCI.h"
#include "libs/Paciente.h"
#include "libs/SalaUCI.h"
#include "libs/Reporte.h"
#include "libs/Separar_Pacientes.cpp"
#include "libs/Separar_config.cpp"
#include "libs/procesar_binarios.cpp"
#include "libs/DeteccionAnomilia.cpp"
#include "libs/creacionRerpote.cpp"

using namespace std;
Configuracion *configCon;
ReporteText *reporteText = new ReporteText[1000];

SalaUCI sala;


string obtenerDirectorioActual() {
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != nullptr) {
        return string(cwd);
    }
    return "";
}

void cargarConfig() 
{
    cout << "Cargando archivo de configuracion..." << endl;
    cargarConfiguracion(obtenerDirectorioActual() + "/data/configuracion.txt", configCon);
   
}

void cargarDatosPacientes() 
{
    cout << "Cargando datos de pacientes... " << endl;
    cargarPacientes(obtenerDirectorioActual()  + "/data/pacientes_small.csv");
    
}

void leerArchivoBSF() 
{
    cout << "Leyendo archivo .bsf..." << endl;
    sala = leerEstructuraBinaria(obtenerDirectorioActual() + "/patient_readings_simulation_tiny.bsf");
    //cout << "Dato: " << static_cast<int>(sala.maquinas[0].idMaquina) << "\n";
}

void generarReporteAnomalias() 
{
    cout << "Generando reporte de anomalías..." << endl;
    deteccionAnomala("1", sala, configCon);
}

void calcularEstadisticas() 
{
    cout << "Calculando estadísticas..." << endl;
    calcular(sala,reporteText, "1", configCon);
}

void exportarDatosProcesados() 
{
    cout << "Exportando datos procesados..." << endl;
    // Implementar exportación de datos
}

int main() 
{
    int opcion;
    char** Prueba = nullptr;
    string TiposDatos= "2; PA; HA387946; Alberto; Torres; 27/11/1960; 3080915628; atorres@example.com; O+; Coomeva; Medisanitas";
    char delimitador = ';';
    Paciente pacienteCon;
    do 
    {
        cout << "Menú Principal:" << endl;
        cout << "1. Cargar archivo de configuracion y datos de pacientes" << endl;
        cout << "2. Leer archivo .bsf" << endl;
        cout << "3. Generar reporte de anomalías" << endl;
        cout << "4. Calcular estadísticas" << endl;
        cout << "5. Exportar datos procesados" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) 
        {
            case 1:
                cargarConfig();
                cargarDatosPacientes();
                break;
            case 2:
                leerArchivoBSF();
                break;
            case 3:
                generarReporteAnomalias();
                break;
            case 4:
                calcularEstadisticas();
                break;
            case 5:
                exportarDatosProcesados();
                break;
            case 6:
                cout << "Saliendo del programa..." << endl;
                break;
            case 7:
                cout << "voy acá \n";

                pacAStruct(Prueba, pacienteCon);
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 6);

    return 0;
}
