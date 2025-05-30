#ifndef INGRESO_H
#define INGRESO_H

#include "transaccion.h"
using namespace std;

//Heredación
class Ingreso : public Transaccion {
private:
    string fuente;

public:
    Ingreso();
    Ingreso(double _monto, string _fecha, string _descripcion, Categoria* _categoria, string _fuente);

    string getFuente();

    string mostrarDetalles() override;
    double calcularImpuesto() override;
    bool esIngreso() const override;
};

#endif
