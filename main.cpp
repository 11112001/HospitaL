#include <iostream>

using namespace std;

int main() 
{
    int opcion = 0;

    while(opcion != 6) 
    {
        cout << "\n======= MENÚ PRINCIPAL =======\n";
        cout << "1. Cargar archivo de configuración y datos de pacientes\n";
        cout << "2. Leer archivo .bsf\n";
        cout << "3. Generar reporte de anomalías\n";
        cout << "4. Calcular estadísticas\n";
        cout << "5. Exportar datos procesados\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opción (1-6): ";
        
        cin >> opcion;
        
        switch(opcion) 
        {
            case 1:
                cout << "[1] \n";
                break;
            case 2:
                cout << "[2] \n";
                break;
            case 3:
                cout << "[3] \n";
                break;
            case 4:
                cout << "[4] .\n";
                break;
            case 5:
                cout << "[5] \n";
                break;
            case 6:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opción inválida. Por favor ingrese un número del 1 al 6.\n";
                
        }
    }

    return 0;
}