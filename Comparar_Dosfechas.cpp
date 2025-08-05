//nuevo código
#include <string>

using namespace std;

bool compararFechas(const string& fecha1, const string& fecha2) 
{
    if(fecha1 > fecha2)
    {
        return true;
    }
    return false;  
}
