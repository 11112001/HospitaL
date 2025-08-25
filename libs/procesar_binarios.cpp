// #include "Config.h"
#include "Lectura.h"
#include "MaquinaUCI.h"
#include "Medicion.h"
#include "SalaUCI.h"
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

void leerDato(ifstream &ar, void *destino, size_t tama) {
  ar.read(reinterpret_cast<char *>(destino), tama);
}

// Función para leer el archivo .bsf


SalaUCI leerEstructuraBinaria(string Ruta) {

  ifstream archivo(Ruta, ios::binary);

  if (!archivo) {
    cerr << "Error al abrir el archivo / Archivo no encontrado" << "\n";
    exit(1);
  }

  SalaUCI sala;

  leerDato(archivo, &sala.idSala, sizeof(sala.idSala));
  leerDato(archivo, &sala.numMaquinas, sizeof(sala.numMaquinas));

  sala.idSala = sala.idSala;
  sala.numMaquinas = sala.numMaquinas;

  // Si sala.num_maquinas es mayor que 0, reservar un arreglo dinámico de
  // Maquina de ese tamaño; si no, poner el puntero a nullptr
  sala.maquinas =
      (sala.numMaquinas ? new MaquinaUCI[sala.numMaquinas] : nullptr);

  int numero_Maquinas = static_cast<int>(sala.numMaquinas);
  for (int i = 0; i < numero_Maquinas; ++i) {

    MaquinaUCI &maq = sala.maquinas[i];

    leerDato(archivo, &maq.idMaquina, sizeof(maq.idMaquina));
    leerDato(archivo, &maq.numMediciones, sizeof(maq.numMediciones));

    sala.maquinas[i].idMaquina = static_cast<int>(maq.idMaquina);
    sala.maquinas[i].numMediciones = maq.numMediciones;

    maq.mediciones =
        (maq.numMediciones ? new Medicion[maq.numMediciones] : nullptr);

    for (int m = 0; m < maq.numMediciones; ++m) {
      Medicion &med = maq.mediciones[m];

      leerDato(archivo, &med.idPaciente, 11);
      leerDato(archivo, &med.fechaHora, 24);
      leerDato(archivo, &med.numLecturas, 4);

      strcpy(sala.maquinas[i].mediciones[m].idPaciente, med.idPaciente);
      strcpy(sala.maquinas[i].mediciones[m].fechaHora, med.fechaHora);
      sala.maquinas[i].mediciones[m].numLecturas = med.numLecturas;

      med.lecturas = (med.numLecturas ? new Lectura[med.numLecturas] : nullptr);

      for (int r = 0; r < med.numLecturas; ++r) {
        Lectura &L = med.lecturas[r];
        leerDato(archivo, &L.tipoSensor, 1);
        sala.maquinas[i].mediciones[m].lecturas[r].tipoSensor = L.tipoSensor;

        char dato[8];
        if (L.tipoSensor == 'P') {
          leerDato(archivo, dato, 8);
        } else {
          leerDato(archivo, &L.valor, sizeof(L.valor));
        }

        sala.maquinas[i].mediciones[m].lecturas[r].valor = L.valor;

        if (L.tipoSensor == 'P') {
          cout << "  Valor: " << dato << "\n";
        } else {
          cout << "  Valor: " << L.valor << "\n";
        }
      }
    }
  }

  return sala;
}