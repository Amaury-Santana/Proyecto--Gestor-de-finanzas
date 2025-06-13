// Amaury Manuel Santana Barrios - A01708442
// Archivo: ingreso.h
// Descripción: Define la clase Ingreso que representa una transacción de
// entrada de dinero, como salario, beca, etc.

#ifndef INGRESO_H
#define INGRESO_H

#include "transaccion.h"
using namespace std;

class Ingreso : public Transaccion {
private:
    string fuente;  // Origen del ingreso (ejemplo:  Sueldo, Beca)

public:
    // Constructor por defecto
    Ingreso();

    // Constructor con parámetros
    Ingreso(double _monto, string _fecha, string _descripcion,
            Categoria* _categoria, string _fuente);

    // getFuente()
    // Retorna el origen del ingreso
    string getFuente();

    // mostrarDetalles()
    // Devuelve un string con detalles del ingreso
    string mostrarDetalles();

    // calcularImpuesto()
    // Calcula el impuesto generado por el ingreso
    double calcularImpuesto();

    // esIngreso()
    // Retorna true ya que es un ingreso
    bool esIngreso() const;
};

#endif
