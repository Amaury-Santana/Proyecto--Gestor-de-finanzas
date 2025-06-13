// Amaury Manuel Santana Barrios - A01708442
// Archivo: resumenmensual.h
// Descripción: Define la clase ResumenMensual, que organiza, almacena y
// resume transacciones de un mes específico.

#ifndef RESUMENMENSUAL_H
#define RESUMENMENSUAL_H

#include "transaccion.h"

class ResumenMensual {
private:
    int mes;                            // Mes del resumen (1 a 12)
    int year;                           // Año del resumen
    Transaccion* transacciones[100];   // Arreglo de transacciones (máx 100)
    int contador;                      // Número de transacciones registradas

public:
    // Constructor por defecto
    ResumenMensual();

    // Constructor con parámetros: mes y año
    ResumenMensual(int _mes, int _year);

    // agregarTransaccion()
    // Agrega una transacción al arreglo si hay espacio
    void agregarTransaccion(Transaccion* t);

    // calcularBalance()
    // Calcula la diferencia entre ingresos y gastos
    double calcularBalance();

    // calcularImpuestos()
    // Calcula impuestos generados menos deducibles
    double calcularImpuestos();

    // mostrarResumen()
    // Imprime en consola el resumen mensual
    void mostrarResumen();

    // getTransacciones()
    // Devuelve el arreglo de transacciones
    Transaccion** getTransacciones();

    // getCantidadTransacciones()
    // Devuelve el número total de transacciones
    int getCantidadTransacciones();
};

#endif
