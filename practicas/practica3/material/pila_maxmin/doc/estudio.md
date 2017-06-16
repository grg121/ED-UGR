# PRÁCTICA_3.pdf 

## T.D.A Pila_maxmin
### Especificación: 
Una Pila_maxmin es un tipo de contenedor especialmente diseñado para operar en un contexto LIFO (Last-in-First-out), en el que los elementos son insertados y extraidos solo por el final del contenedor (tope), con la peculiaridad de que se almacena, en cada dato, información sobre el conjunto que había en el momento de su insercción (máximo y mínimo del conjunto), de forma que en cualquier momento se pueda saber cuáles son estos valores sin acceder a los miembros internos de la pila (accediendo sólo al tope). La pila almacena una secuencia de elementos (compuestos por un valor, y el máximo y mínimo de los valores contenidos desde esa posición en adelante) de la forma: {a0,a1, ... , a(n-1)} y:
* Las consultas se realizan sobre a(n-1).
* Los borrados se hacen sobre a(n-1).
* Las insercciones se hacen sobre a(n-1).
* No se puede acceder a ningún dato de la pila que no sea el tope. 
### Operaciones básicas:
* Constructor por defecto (Pila vacía).
* Acceso al tope de la pila (consulta).
* Eliminar el tope de la pila. 
* Consultar máximo y mínimo valores almacenados en la pila.
* Comprobar si la pila está vacía.

