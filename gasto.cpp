// Implementación de Gasto
// Muestra detalles del gasto y aplica deducción si es deducible (8%), a diferencia de ingreso este porcentaje solo se aplica si si es deducible y eso lo indica el usuario.


#include "gasto.h"

Gasto::Gasto() : Transaccion() {
    tipoPago = "";
    esDeducible = false;
}

Gasto::Gasto(double _monto, string _fecha, string _descripcion, Categoria* _categoria, string _tipoPago, bool _esDeducible)
: Transaccion(_monto, _fecha, _descripcion, _categoria) {
    tipoPago = _tipoPago;
    esDeducible = _esDeducible;
}

string Gasto::getTipoPago() {
    return tipoPago;
}

bool Gasto::getEsDeducible() {
    return esDeducible;
}
//Implemento el método que sobrescribe el virtual
string Gasto::mostrarDetalles() {
    return "Gasto de " + to_string(monto) + " usando " + tipoPago +
           " [" + categoria->getNombre() + "] - " + fecha + " - " + descripcion;
}

// Cálculo de impuesto solo si el gasto es deducible
double Gasto::calcularImpuesto() {
    if (esDeducible) {
        return monto * 0.08;
    } else {
        return 0.0;
    }
}

bool Gasto::esIngreso() const {
    return false;
}


