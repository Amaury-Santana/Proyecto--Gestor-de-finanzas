#include <iostream>
#include "categoria.h"
#include "ingreso.h"
#include "gasto.h"
#include "resumenmensual.h"
using namespace std;

int main() {
    Categoria cat1("Sueldo", "Ingreso");
    Categoria cat2("Comida", "Gasto");

    Transaccion* ingreso1 = new Ingreso(15000, "2025-06-01", "Pago mensual", &cat1, "Empresa XYZ");
    Transaccion* gasto1 = new Gasto(2000, "2025-06-05", "Restaurante", &cat2, "Tarjeta", true);

    ResumenMensual resumen(6, 2025);
    resumen.agregarTransaccion(ingreso1);
    resumen.agregarTransaccion(gasto1);

    resumen.mostrarResumen();

    

    return 0;
}
