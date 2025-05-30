#ifndef RESUMENMENSUAL_H
#define RESUMENMENSUAL_H

#include <vector>
#include "transaccion.h"
using namespace std;

class ResumenMensual {
private:
    int mes;
    int year;
    vector<Transaccion*> transacciones;

public:
    ResumenMensual();
    ResumenMensual(int _mes, int _year);

    void agregarTransaccion(Transaccion* t);
    double calcularBalance();
    double calcularImpuestos();
    void mostrarResumen();
    const vector<Transaccion*>& getTransacciones();
};

#endif
