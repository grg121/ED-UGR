void Pila_maxmin::quitar()
{
  Lista<elemento>::iterator it = datos.begin() ;
  datos.Borrar(it) ;
  
}

/* _________________________________________________________________________ */

elemento Pila_maxmin::tope()
{

  Lista<elemento>::iterator it = datos.begin() ;

  return *it ; 
}

/* _________________________________________________________________________ */

void Pila_maxmin::poner(int valor)
{
  elemento nuevo;
  nuevo.ele =  valor ;

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
  Lista<elemento>::iterator it = datos.begin() ;

  datos.Insertar(it, nuevo) ;
 
  
}
