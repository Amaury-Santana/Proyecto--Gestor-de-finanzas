// Clase hija de Transaccion que representa un gasto
// Agrega atributos tipoPago y esDeducible


#ifndef GASTO_H
#define GASTO_H

#include "transaccion.h"
using namespace std;

class Gasto : public Transaccion {
private:
    string tipoPago;
    bool esDeducible;

public:
    Gasto();
    Gasto(double _monto, string _fecha, string _descripcion, Categoria* _categoria, string _tipoPago, bool _esDeducible);

    string getTipoPago();
    bool getEsDeducible();

    string mostrarDetalles();    
    double calcularImpuesto();    
    bool esIngreso() const;       
};

#endif
