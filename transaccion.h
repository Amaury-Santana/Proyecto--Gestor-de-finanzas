// Amaury Manuel Santana Barrios - A01708442
// Archivo: transaccion.h
// Descripción: Clase abstracta base para representar una transacción
// financiera. Es la superclase de Ingreso y Gasto.

#ifndef TRANSACCION_H
#define TRANSACCION_H

#include <string>
#include "categoria.h"
using namespace std;

class Transaccion {
protected:
    double monto;             // Monto de la transacción
    string fecha;             // Fecha en formato YYYY-MM-DD
    string descripcion;       // Descripción breve de la transacción
    Categoria* categoria;     // Asociación con una categoría

public:
    // Constructor por defecto
    Transaccion();

    // Constructor con parámetros
    Transaccion(double _monto, string _fecha,
                string _descripcion, Categoria* _categoria);

    // getMonto()
    // Devuelve el monto de la transacción
    double getMonto();

    // getFecha()
    // Retorna la fecha de la transacción
    string getFecha();

    // getDescripcion()
    // Retorna una breve descripción
    string getDescripcion();

    // getCategoria()
    // Devuelve el puntero a la categoría asociada
    Categoria* getCategoria();

    // Métodos virtuales puros para polimorfismo

    // mostrarDetalles()
    // Devuelve una cadena con detalles específicos
    virtual string mostrarDetalles() = 0;

    // calcularImpuesto()
    // Calcula el impuesto generado o deducible
    virtual double calcularImpuesto() = 0;

    // esIngreso()
    // Retorna true si es ingreso, false si es gasto
    virtual bool esIngreso() const = 0;

    // Destructor virtual
    virtual ~Transaccion() {}
};

#endif
