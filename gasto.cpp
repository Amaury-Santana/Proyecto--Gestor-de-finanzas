//gasto.cpp

#include "gasto.h"


// Constructor por defecto:
// Inicializa tipo de pago como cadena vacía y deducible como falso.

Gasto::Gasto() : Transaccion() {
    tipoPago = "";
    esDeducible = false;
}


// Constructor con parámetros:
// Inicializa todos los atributos del gasto, incluyendo si es deducible.

Gasto::Gasto(double _monto, string _fecha, string _descripcion,
             Categoria* _categoria, string _tipoPago, bool _esDeducible)
    : Transaccion(_monto, _fecha, _descripcion, _categoria) {
    tipoPago = _tipoPago;
    esDeducible = _esDeducible;
}


// getTipoPago()
// Regresa el tipo de pago con el que se realizó el gasto.

string Gasto::getTipoPago() {
    return tipoPago;
}


// getEsDeducible()
// Regresa true si el gasto es deducible.

bool Gasto::getEsDeducible() {
    return esDeducible;
}


// mostrarDetalles()
// Implementación del método sobrescrito.
// Devuelve un string con los detalles del gasto.

string Gasto::mostrarDetalles() {
    return "Gasto de " + to_string(monto) + " usando " + tipoPago +
           " [" + categoria->getNombre() + "] - " + fecha +
           " - " + descripcion;
}


// calcularImpuesto()
// Aplica el 8% de deducción si el gasto es deducible.

double Gasto::calcularImpuesto() {
    if (esDeducible) {
        return monto * 0.08;
    } else {
        return 0.0;
    }
}


// esIngreso()
// Indica que esta transacción no es un ingreso (es un gasto).

bool Gasto::esIngreso() const {
    return false;
}
