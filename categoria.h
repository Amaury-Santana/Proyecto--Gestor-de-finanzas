//Clase asociada a transacción para representar una categoría de gasto o ingreso

#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <string>
using namespace std;


class Categoria {
private:
    string nombre;
    string tipo; //"Gasto" o "Ingreso"

public:
    Categoria();
    Categoria(string _nombre, string _tipo);

    string getNombre();
    string getTipo();
};

#endif
