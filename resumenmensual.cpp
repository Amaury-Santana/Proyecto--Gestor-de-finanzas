// Implementación de los métodos de ResumenMensual
// Agrega transacciones, calcula balance e imprime resumen con impuestos y deducciones que es lo que aparece en el resumen mensual

#include "resumenmensual.h"
#include <iostream>
#include <iomanip>
using namespace std;

ResumenMensual::ResumenMensual() {
    mes = 0;
    year = 0;
    contador = 0;
}

ResumenMensual::ResumenMensual(int _mes, int _year) {
    mes = _mes;
    year = _year;
    contador = 0;
}

void ResumenMensual::agregarTransaccion(Transaccion* t) {
    if (contador < 100) {
        transacciones[contador] = t;
        contador++;
    }
}

double ResumenMensual::calcularBalance() {
    double total = 0;

    for (int i = 0; i < contador; i++) {
        if (transacciones[i]->esIngreso()) {
            total += transacciones[i]->getMonto();
        } else {
            total -= transacciones[i]->getMonto();
        }
    }

    return total;
}

double ResumenMensual::calcularImpuestos() {
    double impuestos = 0;
    double deducciones = 0;

    for (int i = 0; i < contador; i++) {
        if (transacciones[i]->esIngreso()) {
            impuestos += transacciones[i]->calcularImpuesto();
        } else {
            deducciones += transacciones[i]->calcularImpuesto();
        }
    }

    return impuestos - deducciones;
}

void ResumenMensual::mostrarResumen() {
    cout << fixed << setprecision(2);
    cout << "Resumen del mes " << mes << "/" << year << endl;

    for (int i = 0; i < contador; i++) {
        cout << transacciones[i]->mostrarDetalles() << endl;
    }

    double impuestos = 0;
    double deducciones = 0;

    for (int i = 0; i < contador; i++) {
        if (transacciones[i]->esIngreso()) {
            impuestos += transacciones[i]->calcularImpuesto();
        } else {
            deducciones += transacciones[i]->calcularImpuesto();
        }
    }

    double totalImpuestos = impuestos - deducciones;

    cout << "Impuestos generados: " << impuestos << endl;
    cout << "Deducciones aplicadas: " << deducciones << endl;
    cout << "Total neto a pagar al SAT: " << totalImpuestos << endl;
    cout << "Balance final de ingresos y gastos: " << calcularBalance() << endl;
}

Transaccion** ResumenMensual::getTransacciones() {
    return transacciones;
}

int ResumenMensual::getCantidadTransacciones() {
    return contador;
}
