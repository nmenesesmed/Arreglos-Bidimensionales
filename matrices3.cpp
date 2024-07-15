#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Ingrese el valor de n: "; cin >> n;

    int filas = n;
    int columnas = 3 * n;
    int matriz[filas][columnas];

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            matriz[i][j] = 0;
        }
    }

    for (int j = 0; j < columnas; ++j) {
        matriz[0][j] = 1;
        matriz[filas - 1][j] = 1;
    }

    for (int i = 0; i < filas; ++i) {
        matriz[i][0] = 1;
        matriz[i][columnas - 1] = 1;
    }

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << matriz[i][j];
        }
        cout << endl;
    }

    return 0;
}