#include "categoria.h"

Categoria::Categoria() {
    nombre = "";
    tipo = "";
}

Categoria::Categoria(string _nombre, string _tipo) {
    nombre = _nombre;
    tipo = _tipo;
}

string Categoria::getNombre() {
    return nombre;
}

string Categoria::getTipo() {
    return tipo;
}
