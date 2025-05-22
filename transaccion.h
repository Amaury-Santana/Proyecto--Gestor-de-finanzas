#ifndef TRANSACCION_H
#define TRANSACCION_H

#include <string>
#include "categoria.h"
using namespace std;

class Transaccion {
protected:
    double monto;
    string fecha;
    string descripcion;
    Categoria* categoria; // Demuestra la asociación con una categoría

public:
    Transaccion();
    Transaccion(double _monto, string _fecha, string _descripcion, Categoria* _categoria);

    //Estos son los  métodos de acceso
    double getMonto();
    string getFecha();
    string getDescripcion();
    Categoria* getCategoria();

    //Y estos son los  métodos virtuales que se sobreescriben en las hijas
    virtual string mostrarDetalles() = 0;
    virtual double calcularImpuesto() = 0;
};

#endif
