//#include <cstddef>
#include <iostream>

//Por qué da warning!
//#include "libs/Config.h"
//#include "libs/Paciente.h"
#include "libs/Separar_Pacientes.cpp"
#include "libs/Separar_config.cpp"

using namespace std;

void cargarConfiguracion() 
{
    cout << "Cargando archivo de configuracion..." << endl;
    // Implementar carga de archivo de configuracion
}

void cargarDatosPacientes() 
{
    cout << "Cargando datos de pacientes..." << endl;
    // Implementar carga de archivo de pacientes
}

void leerArchivoBSF() 
{
    cout << "Leyendo archivo .bsf..." << endl;
    // Implementar lectura de archivo .bsf
}

void generarReporteAnomalias() 
{
    cout << "Generando reporte de anomalías..." << endl;
    // Implementar reporte de anomalías
}

void calcularEstadisticas() 
{
    cout << "Calculando estadísticas..." << endl;
    // Implementar cálculo de estadísticas
}

void exportarDatosProcesados() 
{
    cout << "Exportando datos procesados..." << endl;
    // Implementar exportación de datos
}

int main() 
{
    int opcion;
    char* Prueba = nullptr;
    string TiposDatos= "T,36.0,38.0";
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
                cargarConfiguracion();
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
                Prueba = separarConfiguracion(TiposDatos);
                cout << "Respuesta: " << Prueba[0] <<"\n";
                cout << "Respuesta: " << Prueba[1] <<"\n";
                cout << "Respuesta: " << Prueba[2] <<"\n";
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 6);

    return 0;
}
