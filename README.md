# Proyecto Gestor de finanzas
El proyecto nace sobre la necesidad como adolescente de controlar mi dinero y llevar una mejor vida financieria. Es un sistema que permite al usuario gestionar sus finanzas mensuales registrando ingresos y gastos, clasificándolos por categorías, y mostrando un resumen con balance, impuestos generados y deducciones aplicadas.


## Funcionalidad
El programa implementa un menú interactivo donde el usuario puede:

- Registrar ingresos (monto, fecha, fuente, categoría)
- Registrar gastos (monto, fecha, tipo de pago, si es deducible, categoría)
- Ver un resumen mensual con:
  - Lista de transacciones
  - Impuestos generados por ingresos
  - Deducciones por gastos deducibles
  - Balance final del mes

## Clases utilizadas
- Transaccion (abstracta): clase base con atributos generales como monto, fecha y categoría.
- Ingreso: hereda de Transaccion, agrega fuente de ingreso. Genera impuesto del 10%.
- Gasto: hereda de Transaccion, agrega tipo de pago y si es deducible. Aplica deducción del 8% si es deducible.
- Categoria: representa una categoría asociada a cada transacción (por ejemplo: “Sueldo”, “Comida”).
- ResumenMensual: almacena las transacciones del mes, permite calcular impuestos, deducciones y mostrar resumen general.


## Casos que harían que el proyecto no funcione o que tenga que hacer algo al respecto
- Ingresar datos inválidos (montos negativos, fecha vacía, strings vacíos)
- No sobrescribir correctamente los métodos virtuales (-mostrarDetalles() y calcularImpuesto())
- Acceso fuera del límite del arreglo de transacciones (capacidad máxima: 100)
- Intentar instanciar la clase abstracta Transaccion.
- Ingresar texto donde se espera un número (ej. monto o opción de menú)



# Compilación y ejecución

### Compilar:
```bash
g++ categoria.cpp transaccion.cpp ingreso.cpp gasto.cpp resumenmensual.cpp main.cpp -o gestor_finanzas
./gestor_finanzas      # En Linux o mac
gestor_finanzas.exe    # En Windows


