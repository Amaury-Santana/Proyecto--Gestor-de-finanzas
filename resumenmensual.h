// Clase que representa el resumen mensual con todas las transacciones de un mes/año específico
// Contiene un arreglo de Transaccion* y métodos para agregar, calcular balance e imprimir

#include "transaccion.h"

class ResumenMensual {
private:
    int mes;
    int year;
    Transaccion* transacciones[100]; 
    int contador; 
public:
    ResumenMensual();
    ResumenMensual(int _mes, int _year);

    void agregarTransaccion(Transaccion* t);
    double calcularBalance();
    double calcularImpuestos();
    void mostrarResumen();
    Transaccion** getTransacciones();
    int getCantidadTransacciones(); 
};
