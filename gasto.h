// Amaury Manuel Santana Barrios - A01708442
// Archivo: gasto.h
// Descripción: Define la clase Gasto que representa una transacción
// Incluye tipo de pago y si es deducible.

#ifndef GASTO_H
#define GASTO_H

#include "transaccion.h"
using namespace std;

class Gasto : public Transaccion {
private:
    string tipoPago;     // Medio de pago usado (ejemplo: Efectivo, Tarjeta)
    bool esDeducible;    // Indica si el gasto puede deducirse de impuestos

public:
    // Constructor por defecto
    Gasto();

    // Constructor con parámetros
    Gasto(double _monto, string _fecha, string _descripcion,
          Categoria* _categoria, string _tipoPago, bool _esDeducible);

    // getTipoPago()
    // Devuelve el método de pago usado
    string getTipoPago();

    // getEsDeducible()
    // Indica si el gasto es deducible de impuestos
    bool getEsDeducible();

    // mostrarDetalles()
    // Regresa un string con los detalles del gasto
    string mostrarDetalles();

    // calcularImpuesto()
    // Devuelve el impuesto deducible (si aplica)
    double calcularImpuesto();

    // esIngreso()
    // Retorna false ya que es un gasto
    bool esIngreso() const;
};

#endif
