#include <iostream>
using namespace std;
int main() {
  int numPartidos;
  int numCiudades;
  string nombresPartidos[100];
  int votosCiudades[100][100];
  int votosTotalesPartido[100];
  string ciudadGanadora;
  int mayorVotosCiudad = 0;

  cout << "Ingrese el numero de partidos politicos: "; cin >> numPartidos;
  cout << "Ingrese el numero de ciudades: "; cin >> numCiudades;

  for (int i = 0; i < numPartidos; i++) {
    cout << "Ingrese el nombre del partido " << i + 1 << ": "; cin >> nombresPartidos[i];
  }

  // Ingresar los votos de cada ciudad para cada partido
  for (int ciudad = 0; ciudad < numCiudades; ciudad++) {
    cout << "\n-- Ciudad " << ciudad + 1 << " --" << endl;
    for (int partido = 0; partido < numPartidos; partido++) {
      cout << "Votos para " << nombresPartidos[partido] << ": ";
      cin >> votosCiudades[ciudad][partido];
    }
  }

  // Contar los votos totales de cada partido
  for (int ciudad = 0; ciudad < numCiudades; ciudad++) {
    for (int partido = 0; partido < numPartidos; partido++) {
      votosTotalesPartido[partido] += votosCiudades[ciudad][partido];
    }
  }

  // Identificar el partido ganador a nivel nacional
  int ganadorNacional = 0;
  for (int partido = 1; partido < numPartidos; partido++) {
    if (votosTotalesPartido[partido] > votosTotalesPartido[ganadorNacional]) {
      ganadorNacional = partido;
    }
  }
  // Identificar la ciudad con mayor votación para el partido ganador
  for (int ciudad = 0; ciudad < numCiudades; ciudad++) {
    if (votosCiudades[ciudad][ganadorNacional] > mayorVotosCiudad) {
      mayorVotosCiudad = votosCiudades[ciudad][ganadorNacional];
      ciudadGanadora = ciudad;
    }
  }

  // Mostrar los resultados
  cout << "\n** Resultados **" << endl;
  cout << "Partido ganador a nivel nacional: " << nombresPartidos[ganadorNacional] << endl;
  for (int i = 0; i < numCiudades; i++) {
    int partidoGanadorCiudad = 0;
    for (int partido = 0; partido < numPartidos; partido++) {
      if (votosCiudades[i][partido] > votosCiudades[i][partidoGanadorCiudad]) {
        partidoGanadorCiudad = partido;
      }
    }
    cout << "Ciudad " << i + 1 << ": " << nombresPartidos[partidoGanadorCiudad] << endl;
  }
  cout << "Ciudad con mayor votacion para el partido ganador: " << ciudadGanadora << endl;

  return 0;
}