#ifndef GASTO_H
#define GASTO_H

#include "transaccion.h"
using namespace std;

//Heredación
class Gasto : public Transaccion {
private:
    string tipoPago;
    bool esDeducible;

public:
    Gasto();
    Gasto(double _monto, string _fecha, string _descripcion, Categoria* _categoria, string _tipoPago, bool _esDeducible);

    string getTipoPago();
    bool getEsDeducible();

    string mostrarDetalles() override;
    double calcularImpuesto() override;
};

#endif
