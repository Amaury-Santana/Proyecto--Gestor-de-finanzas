// Punto de entrada principal del programa
// Controla el flujo del menú interactivo para registrar ingresos/gastos y mostrar resumen
// Básicamente aqui copie y pegue la estructura de cout y cin para lo que despliega en el menu por cada cosa y fui cambiando, de manera en que se vea profesional.


#include <iostream>
#include <string>
#include "categoria.h"
#include "ingreso.h"
#include "gasto.h"
#include "resumenmensual.h"
using namespace std;

// Limpio la entrada
void limpiarEntrada() {
    cin.clear();
    cin.ignore(1000, '\n'); 
}

int main() {
    int mes, anio;

    cout << " Bienvenido al Gestor de Finanzas \n";
    cout << "Ingresa el número del mes (1-12): ";
    cin >> mes;
    while (cin.fail() || mes < 1 || mes > 12) {
        cout << "Mes inválido, intenta con un número entre 1 y 12: ";
        limpiarEntrada();
        cin >> mes;
    }

    cout << "Ingresa el año (ej.2025): ";
    cin >> anio;
    while (cin.fail() || anio < 1900 || anio > 2100) {
        cout << "Año inválido, intenta con un año razonable: ";
        limpiarEntrada();
        cin >> anio;
    }

    ResumenMensual resumen(mes, anio);

    //Menu interactivo para el usuario
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
            // Agrego ingreso
            float monto;
            string fecha, descripcion, fuente, catNombre, catTipo = "Ingreso";

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
            cout << "Fuente (ej.Salario, Beca, etc.): ";
            getline(cin, fuente);
            cout << "Nombre de categoría: ";
            getline(cin, catNombre);

            Categoria cat(catNombre, catTipo);
            Transaccion* ingreso = new Ingreso(monto, fecha, descripcion, &cat, fuente);
            resumen.agregarTransaccion(ingreso);
            cout << "Ingreso agregado.\n";

        } else if (opcion == 2) {
            // Agrego gasto
            float monto;
            string fecha, descripcion, tipoPago, catNombre, catTipo = "Gasto";
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
            cout << "Tipo de pago (Efectivo, Tarjeta, Transferencia): ";
            getline(cin, tipoPago);
            cout << "¿Es deducible? (1: sí, 0: no): ";
            int d;
            cin >> d;
            while (cin.fail() || (d != 0 && d != 1)) {
                cout << "Entrada inválida, escribe 1 para sí o 0 para no: ";
                limpiarEntrada();
                cin >> d;
            }
            deducible = (d == 1);

            limpiarEntrada();
            cout << "Nombre de categoría: ";
            getline(cin, catNombre);

            Categoria cat(catNombre, catTipo);
            Transaccion* gasto = new Gasto(monto, fecha, descripcion, &cat, tipoPago, deducible);
            resumen.agregarTransaccion(gasto);
            cout << "Gasto agregado.\n";

        // Muestro resumen con los métodos en las clases Ingreso y Gasto
        } else if (opcion == 3) {
            resumen.mostrarResumen();

        } else if (opcion == 4) {
            salir = true;
            cout << "Gracias por usar el gestor, nos vemos\n";

        } else {
            cout << "Opción no válida, intenta otra vez.\n";
        }
    }

    return 0;
}
