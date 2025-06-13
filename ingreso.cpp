//ingreso.cpp

#include "ingreso.h"


// Constructor por defecto:
// Inicializa la fuente como cadena vacía.

Ingreso::Ingreso() : Transaccion() {
    fuente = "";
}


// Constructor con parámetros:
// Inicializa los atributos de un ingreso, incluyendo su fuente.

Ingreso::Ingreso(double _monto, string _fecha, string _descripcion,
                 Categoria* _categoria, string _fuente)
    : Transaccion(_monto, _fecha, _descripcion, _categoria) {
    fuente = _fuente;
}


// getFuente()
// Regresa la fuente de ingreso.

string Ingreso::getFuente() {
    return fuente;
}


// mostrarDetalles()
// Implementación del método sobrescrito.
// Devuelve un string con los detalles del ingreso.

string Ingreso::mostrarDetalles() {
    return "Ingreso de " + to_string(monto) + " por " + fuente +
           " [" + categoria->getNombre() + "] - " + fecha +
           " - " + descripcion;
}


// calcularImpuesto()
// Aplica un impuesto fijo del 10% sobre el monto.

double Ingreso::calcularImpuesto() {
    return monto * 0.10;
}


// esIngreso()
// Indica que esta transacción es un ingreso.

bool Ingreso::esIngreso() const {
    return true;
}
