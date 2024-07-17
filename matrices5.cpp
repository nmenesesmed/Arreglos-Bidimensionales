#include <iostream>
using namespace std;

// Función para encontrar el índice del valor máximo en un arreglo
int maxIndex(int arr[], int size) {
    int maxIdx = 0;
    for (int i = 1; i < size; ++i) {
        if (arr[i] > arr[maxIdx]) {
            maxIdx = i;
        }
    }
    return maxIdx;
}

int main() {
    int n, m;
    cout << "Ingrese el numero de partidos politicos (n): "; cin >> n;
    cout << "Ingrese el numero de ciudades (m): "; cin >> m;

    string partidos[n];
    cout << "Ingrese los nombres de los partidos politicos:\n";
    for (int i = 0; i < n; ++i) {
        cin >> partidos[i];
    }

    string ciudades[m];
    cout << "Ingrese los nombres de las ciudades:\n";
    for (int i = 0; i < m; ++i) {
        cin >> ciudades[i];
    }

    int votos[m][n];
    cout << "Ingrese los votos por cada ciudad y cada partido:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "Ciudad " << ciudades[i] << ", Partido " << partidos[j] << ": ";
            cin >> votos[i][j];
        }
    }

    // El partido que gana la elección a nivel nacional
    int votosTotales[n] = {0};
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            votosTotales[j] += votos[i][j];
        }
    }

    int partidoGanadorNacional = maxIndex(votosTotales, n);
    cout << "El partido que gana la eleccion a nivel nacional es: " << partidos[partidoGanadorNacional] << endl;

    // El partido ganador por cada ciudad
    int ganadoresPorCiudad[m];
    for (int i = 0; i < m; ++i) {
        ganadoresPorCiudad[i] = maxIndex(votos[i], n);
        cout << "El partido ganador en la ciudad " << ciudades[i] << " es: " << partidos[ganadoresPorCiudad[i]] << endl;
    }

    // Ciudad donde tuvo mayor votación el partido ganador
    int ciudadMayorVotacion = 0;
    int maxVotacion = votos[0][partidoGanadorNacional];
    for (int i = 1; i < m; ++i) {
        if (votos[i][partidoGanadorNacional] > maxVotacion) {
            maxVotacion = votos[i][partidoGanadorNacional];
            ciudadMayorVotacion = i;
        }
    }
    cout << "La ciudad donde el partido ganador tuvo mayor votacion es: " << ciudades[ciudadMayorVotacion] << endl;

    return 0;
}