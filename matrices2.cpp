#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Ingrese el tamanio de la matriz cuadrada: ";
    cin >> n;

    int matriz[n][n];
    cout << "Ingrese los elementos de la matriz:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matriz[i][j];
        }
    }

    int suma_diag_secundaria = 0;
    for (int i = 0; i < n; ++i) {
        suma_diag_secundaria += matriz[i][n - 1 - i];
    }

    cout << "La suma de los elementos de la diagonal secundaria es: " << suma_diag_secundaria << endl;

    return 0;
}
