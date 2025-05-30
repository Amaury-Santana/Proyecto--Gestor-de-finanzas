#include "resumenmensual.h"
#include <iostream>
using namespace std;

ResumenMensual::ResumenMensual() {
    mes = 0;
    year = 0;
}

ResumenMensual::ResumenMensual(int _mes, int _year) {
    mes = _mes;
    year = _year;
}

void ResumenMensual::agregarTransaccion(Transaccion* t) {
    transacciones.push_back(t);
}

double ResumenMensual::calcularBalance() {
    double total = 0;

    for (Transaccion* t : transacciones) {
        if (t->esIngreso()) {
            total += t->getMonto();
        } else {
            total -= t->getMonto();
        }
    }

    return total;
}

double ResumenMensual::calcularImpuestos() {
    double impuestos = 0;
    double deducciones = 0;

    for (Transaccion* t : transacciones) {
        if (t->esIngreso()) {
            impuestos += t->calcularImpuesto();
        } else {
            deducciones += t->calcularImpuesto();
        }
    }

    return impuestos - deducciones;
}



void ResumenMensual::mostrarResumen() {
    cout << "Resumen del mes " << mes << "/" << year << endl;

    for (Transaccion* t : transacciones) {
        cout << t->mostrarDetalles() << endl;
    }

    //Separo los impuestos y deducciones
    double impuestos = 0;
    double deducciones = 0;

    for (Transaccion* t : transacciones) {
        if (t->esIngreso()) {
            impuestos += t->calcularImpuesto();
        } else {
            deducciones += t->calcularImpuesto();
        }
    }

    double totalImpuestos = impuestos - deducciones;

    cout << "Impuestos generados: " << impuestos << endl;
    cout << "Deducciones aplicadas: " << deducciones << endl;
    cout << "Total neto a pagar al SAT: " << totalImpuestos << endl;
    cout << "Balance final de ingresos y gastos: " << calcularBalance() << endl;
}


const vector<Transaccion*>& ResumenMensual::getTransacciones() {
    return transacciones;
}
