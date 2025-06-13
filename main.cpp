// Amaury Manuel Santana Barrios - A01708442
// Archivo: main.cpp
// Descripción:
// Interfaz principal con menú para registrar transacciones
// (ingresos y gastos) y mostrar el resumen financiero mensual.

#include <iostream>     // Para impresión y entrada estándar
#include <string>       // Para el uso de strings

// Bibliotecas con las clases del proyecto
#include "categoria.h"
#include "ingreso.h"
#include "gasto.h"
#include "resumenmensual.h"

using namespace std;

// limpiarEntrada()
// Limpia errores en cin y descarta entrada inválida del búfer
void limpiarEntrada() {
    cin.clear();
    cin.ignore(1000, '\n');
}

int main() {
    int mes, anio;

    cout << " Bienvenido al Gestor de Finanzas \n";

    // Solicita y valida el número del mes
    cout << "Ingresa el número del mes (1-12): ";
    cin >> mes;
    while (cin.fail() || mes < 1 || mes > 12) {
        cout << "Mes inválido, intenta con un número entre 1 y 12: ";
        limpiarEntrada();
        cin >> mes;
    }

    // Solicita y valida el año
    cout << "Ingresa el año (ejemplo: 2025): ";
    cin >> anio;
    while (cin.fail() || anio < 2024 || anio > 2100) {
        cout << "Año inválido, intenta con un año razonable: ";
        limpiarEntrada();
        cin >> anio;
    }

    // Crea el resumen del mes con el año proporcionado
    ResumenMensual resumen(mes, anio);

    // Menú principal interactivo
    bool salir = false;
    while (!salir) {
        cout << "\n ---MENÚ---\n";
        cout << "1. Agregar ingreso\n";
        cout << "2. Agregar gasto\n";
        cout << "3. Mostrar resumen\n";
        cout << "4. Salir\n";
        cout << "Opción: ";

        int opcion;
        cin >> opcion;

        if (cin.fail()) {
            cout << "Entrada inválida, intenta de nuevo.\n";
            limpiarEntrada();
            continue;
        }

        if (opcion == 1) {
            // Agregar ingreso
            float monto;
            string fecha, descripcion, fuente, catNombre;
            string catTipo = "Ingreso";

            cout << "Monto: ";
            cin >> monto;
            while (cin.fail() || monto <= 0) {
                cout << "Monto inválido, intenta de nuevo: ";
                limpiarEntrada();
                cin >> monto;
            }

            limpiarEntrada();
            cout << "Fecha (YYYY-MM-DD): ";
            getline(cin, fecha);
            cout << "Descripción: ";
            getline(cin, descripcion);
            cout << "Fuente (ej. Salario, Beca): ";
            getline(cin, fuente);
            cout << "Nombre de categoría: ";
            getline(cin, catNombre);

            Categoria cat(catNombre, catTipo);
            Transaccion* ingreso = new Ingreso(
                monto, fecha, descripcion, &cat, fuente);
            resumen.agregarTransaccion(ingreso);
            cout << "Ingreso agregado.\n";

        } else if (opcion == 2) {
            // Agregar gasto
            float monto;
            string fecha, descripcion, tipoPago, catNombre;
            string catTipo = "Gasto";
            bool deducible;

            cout << "Monto: ";
            cin >> monto;
            while (cin.fail() || monto <= 0) {
                cout << "Monto inválido, intenta de nuevo: ";
                limpiarEntrada();
                cin >> monto;
            }

            limpiarEntrada();
            cout << "Fecha (YYYY-MM-DD): ";
            getline(cin, fecha);
            cout << "Descripción: ";
            getline(cin, descripcion);
            cout << "Tipo de pago (Efectivo, Tarjeta, etc.): ";
            getline(cin, tipoPago);
            cout << "¿Es deducible? (1: sí, 0: no): ";
            int d;
            cin >> d;
            while (cin.fail() || (d != 0 && d != 1)) {
                cout << "Entrada inválida, escribe 1 o 0: ";
                limpiarEntrada();
                cin >> d;
            }
            deducible = (d == 1);

            limpiarEntrada();
            cout << "Nombre de categoría: ";
            getline(cin, catNombre);

            Categoria cat(catNombre, catTipo);
            Transaccion* gasto = new Gasto(
                monto, fecha, descripcion, &cat, tipoPago, deducible);
            resumen.agregarTransaccion(gasto);
            cout << "Gasto agregado.\n";

        } else if (opcion == 3) {
            // Mostrar resumen mensual de ingresos y gastos
            resumen.mostrarResumen();

        } else if (opcion == 4) {
            salir = true;
            cout << "Gracias por usar el gestor, nos vemos.\n";

        } else {
            cout << "Opción no válida, intenta otra vez.\n";
        }
    }

    return 0;
}
