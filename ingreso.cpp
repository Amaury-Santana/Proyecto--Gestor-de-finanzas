// Implementación de Ingreso
// Muestra detalles del ingreso e impone una tasa fija del 10% como impuesto (importante decir que siempre la aplicara para el proyecto)


#include "ingreso.h"

Ingreso::Ingreso() : Transaccion() {
    fuente = "";
}

Ingreso::Ingreso(double _monto, string _fecha, string _descripcion, Categoria* _categoria, string _fuente)
: Transaccion(_monto, _fecha, _descripcion, _categoria) {
    fuente = _fuente;
}

string Ingreso::getFuente() {
    return fuente;
}
//Implemento el método que sobreescribe el virtual
string Ingreso::mostrarDetalles() {
    return "Ingreso de " + to_string(monto) + " por " + fuente +
           " [" + categoria->getNombre() + "] - " + fecha + " - " + descripcion;
}


//Impuesto fijo del 10% sobre ingresos
double Ingreso::calcularImpuesto() {
    return monto * 0.10;
}
bool Ingreso::esIngreso() const {
    return true; 
}
