#include <iostream>
#include "categoria.h"
#include "ingreso.h"
#include "gasto.h"
using namespace std;

int main() {
    
    Categoria categoriaIngreso("Sueldo", "Ingreso");
    Categoria categoriaGasto("Renta", "Gasto");

    //Creo los objetos concretos (como ejemplo)
    Ingreso ingreso1(12000, "2025-05-01", "Pago mensual", &categoriaIngreso, "Empresa DHL");
    Gasto gasto1(4000, "2025-05-03", "Pago de renta", &categoriaGasto, "Transferencia", true);

    //Muestro resultados de métodos sobreescritos
    cout << ingreso1.mostrarDetalles() << endl;
    cout << "Impuesto sobre ingreso: " << ingreso1.calcularImpuesto() << endl;

    cout << gasto1.mostrarDetalles() << endl;
    cout << "Impuesto sobre gasto: " << gasto1.calcularImpuesto() << endl;

    return 0;
}
