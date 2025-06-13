//resumenmensual.cpp

#include "resumenmensual.h"
#include <iostream>     // Para cout
#include <iomanip>      // Para setprecision
using namespace std;

// Constructor por defecto: inicializa mes, año y contador
ResumenMensual::ResumenMensual() {
    mes = 0;
    year = 0;
    contador = 0;
}

// Constructor con parámetros: establece mes y año del resumen
ResumenMensual::ResumenMensual(int _mes, int _year) {
    mes = _mes;
    year = _year;
    contador = 0;
}

// agregarTransaccion()
// Agrega un puntero a transacción al arreglo si hay espacio
void ResumenMensual::agregarTransaccion(Transaccion* t) {
    if (contador < 100) {
        transacciones[contador] = t;
        contador++;
    }
}

// calcularBalance()
// Retorna la diferencia entre ingresos y gastos acumulados
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

// calcularImpuestos()
// Suma impuestos generados por ingresos y deduce los de gastos
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

// mostrarResumen()
// Imprime en consola el resumen mensual completo con detalle
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
    cout << "Balance final de ingresos y gastos: "
         << calcularBalance() << endl;
}

// getTransacciones()
// Devuelve el arreglo de transacciones registradas
Transaccion** ResumenMensual::getTransacciones() {
    return transacciones;
}

// getCantidadTransacciones()
// Retorna la cantidad actual de transacciones almacenadas
int ResumenMensual::getCantidadTransacciones() {
    return contador;
}
