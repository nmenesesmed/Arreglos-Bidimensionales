#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Ingrese el tamaño de la matriz cuadrada: "; cin >> n;

    int matriz[n][n];

    // Solicitar al usuario el tamaño de la matriz cuadrada
    cout << "Ingrese los elementos de la matriz:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matriz[i][j];
        }
    }

    // Calcular la sumatoria de los elementos por encima de la diagonal principal
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            sum += matriz[i][j];
        }
    }

    // Mostrar el resultado de la sumatoria
    cout << "La sumatoria de los elementos por encima de la diagonal principal es: " << sum << endl;

    return 0;
}