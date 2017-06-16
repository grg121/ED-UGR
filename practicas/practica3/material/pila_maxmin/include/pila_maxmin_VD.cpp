void Pila_maxmin::quitar()
{
  datos.Borrar(datos.size()-1) ; 
}

/* _________________________________________________________________________ */

elemento Pila_maxmin::tope()
{
  return datos[datos.size()-1];
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
  datos.Insertar(nuevo, datos.size());
}
