// Amaury Manuel Santana Barrios - A01708442
// Archivo: categoria.h
// Descripción: Representa una categoría que clasifica una transacción como
// ingreso o gasto (por ejemplo: Comida, Sueldo, Transporte, etc.)

#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <string>
using namespace std;

class Categoria {
private:
    string nombre;  // Nombre de la categoría (ejemplo: "Comida", "Renta")
    string tipo;    // Tipo de transacción: "Gasto" o "Ingreso"

public:
    // Constructor por defecto
    Categoria();

    // Constructor con parámetros: nombre y tipo
    Categoria(string _nombre, string _tipo);

    // getNombre()
    // Retorna el nombre de la categoría
    string getNombre();

    // getTipo()
    // Retorna el tipo asociado ("Gasto" o "Ingreso")
    string getTipo();
};

#endif
