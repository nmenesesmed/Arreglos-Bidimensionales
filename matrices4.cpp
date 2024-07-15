#include <iostream>
using namespace std;
int main() {
  int diasSemana = 7;
  int semanasMes = 4;
  float ventas[semanasMes][diasSemana];
  float totalVentas = 0.0f;

  for (int semana = 0; semana < semanasMes; semana++) {
    for (int dia = 0; dia < diasSemana; dia++) {
      cout << "Ingrese las ventas del dia " << dia + 1 << " de la semana " << semana + 1 << ": ";
      cin >> ventas[semana][dia];
    }
  }

  for (int semana = 0; semana < semanasMes; semana++) {
    float ventasSemana = 0.0f;
    for (int dia = 0; dia < diasSemana; dia++) {
      ventasSemana += ventas[semana][dia];
    }
    cout << "Ventas semana " << semana + 1 << ": " << ventasSemana << endl;
    totalVentas += ventasSemana;
  }

  cout << "Venta total del mes: " << totalVentas << endl;

  return 0;
}