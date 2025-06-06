// Métodos comunes de la clase Transaccion
// Getters para monto, fecha, descripción y categoría

#include "transaccion.h"

Transaccion::Transaccion() {
    monto = 0.0;
    fecha = "";
    descripcion = "";
    categoria = nullptr;
}

Transaccion::Transaccion(double _monto, string _fecha, string _descripcion, Categoria* _categoria) {
    monto = _monto;
    fecha = _fecha;
    descripcion = _descripcion;
    categoria = _categoria;
}

double Transaccion::getMonto() {
    return monto;
}

string Transaccion::getFecha() {
    return fecha;
}

string Transaccion::getDescripcion() {
    return descripcion;
}

Categoria* Transaccion::getCategoria() {
    return categoria;
}
