void Pila_maxmin::quitar()
{
  Cola<elemento> aux;

  int size = num_elem() -1;

  // Cogemos todos menos el ultimo
  for (int i = 0; i<size; i++)
  {
    aux.poner(datos.frente());
    datos.quitar();
  }

  datos = aux;

}

/* _________________________________________________________________________ */

elemento Pila_maxmin::tope()
{
  Cola<elemento> aux = datos;

  elemento el = aux.frente();

  while (!aux.vacia())
  {
      el.ele = aux.frente().ele;
      el.maximo = aux.frente().maximo;
      el.minimo = aux.frente().minimo; 
      aux.quitar();
  }

  return el;
}

/* _________________________________________________________________________ */

void Pila_maxmin::poner(int valor)
{
  elemento nuevo;
  nuevo.ele = valor;

  if (vacia())
  {
    nuevo.maximo = valor;
    nuevo.minimo = valor ; 

  }
  else
  {
    elemento anterior = tope();
    nuevo.maximo = (valor > anterior.maximo) ? valor : anterior.maximo;
    nuevo.minimo = (valor < anterior.minimo) ? valor : anterior.minimo; 

  }
  datos.poner(nuevo);
}
