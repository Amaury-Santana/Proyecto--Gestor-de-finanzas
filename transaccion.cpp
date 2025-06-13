//transaccion.cpp

#include "transaccion.h"

// Constructor por defecto
// Inicializa valores vacíos o nulos
Transaccion::Transaccion() {
    monto = 0.0;
    fecha = "";
    descripcion = "";
    categoria = nullptr;
}

// Constructor con parámetros
// Recibe valores y los asigna a atributos
Transaccion::Transaccion(double _monto, string _fecha,
                         string _descripcion, Categoria* _categoria) {
    monto = _monto;
    fecha = _fecha;
    descripcion = _descripcion;
    categoria = _categoria;
}

// getMonto()
// Retorna el monto asociado a la transacción
double Transaccion::getMonto() {
    return monto;
}

// getFecha()
// Devuelve la fecha en formato string
string Transaccion::getFecha() {
    return fecha;
}

// getDescripcion()
// Devuelve el texto descriptivo de la transacción
string Transaccion::getDescripcion() {
    return descripcion;
}

// getCategoria()
// Devuelve el puntero a la categoría asociada
Categoria* Transaccion::getCategoria() {
    return categoria;
}
