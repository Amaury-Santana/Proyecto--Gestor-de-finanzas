# Proyecto Gestor de finanzas
El proyecto nace sobre la necesidad como adolescente de controlar mi dinero y llevar una mejor vida financieria.Es un sistema que simula un gestor de finanzas personales, permitiendo registrar ingresos y gastos mensuales, categorizarlos, y calcular el balance e impuestos de cada mes.
Se aplica una estructura de clases basada en herencia, agregación y composición para representar distintos tipos de transacciones. Las clases Gasto e Ingreso heredan de la clase abstracta Transaccion. Cada transacción está asociada a una Categoria, y todas se agrupan dentro de un ResumenMensual.

# Funcionalidad
El programa permite:

-Registrar ingresos y gastos con fecha, descripción, monto y categoría.

-Clasificar las transacciones por medio de objetos Categoria.

-Consultar un resumen mensual con:

  1. Total de ingresos

  2. Total de gastos

  3. Cálculo de impuestos

  4. Balance final del mes

# Casos que harían que el proyecto no funcione o que tenga que hacer algo al respecto
Pense en los siguientes:

Monto negativo o strings vacíos en descripcion, fuente o tipoPago.

Input para fecha con signos o demás caracteres.

Instanciar Transaccion directamente, no compilaria porque busco hacerla abstracta.

No sobrescribir métodos virtuales correctamente,lo que generaria un comportamiento inesperado.

Inconsistencia entre tipo de transacción y tipo de categoría.


# Consideraciones para avance 2 
Para este avance no añadi el codigo de la clase ResumenMensual ya que genere mi proyecto de una forma que se puedan usar todos los temas que llevaremos acabo y esta clase depende de si misma de polimorfismo con puntores y demás y eso todavia no lo hemos visto. Puse las demás clases que demuestran las 3 subcompetencias a evaluar este avance y lo ire cambiando, de igual forma genere un main.cpp para este avance y se ira cmabiando. Gracias

Para correr y compilar este main.cpp:
g++ main.cpp categoria.cpp transaccion.cpp ingreso.cpp gasto.cpp -o gestor_finanzas
./gestor_finanzas  o   gestor_finanzas.exe



