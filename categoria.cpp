// categoria.cpp

#include "categoria.h"


// Constructor por defecto:
// Inicializa los atributos nombre y tipo como cadenas vacías.

Categoria::Categoria() {
    nombre = "";
    tipo = "";
}


// Constructor con parámetros:
// Inicializa los atributos nombre y tipo con los valores dados.

Categoria::Categoria(string _nombre, string _tipo) {
    nombre = _nombre;
    tipo = _tipo;
}


// getNombre()
// Regresa el nombre de la categoría.

string Categoria::getNombre() {
    return nombre;
}


// getTipo()
// Regresa el tipo de categoría (por ejemplo: ingreso o gasto).

string Categoria::getTipo() {
    return tipo;
}
