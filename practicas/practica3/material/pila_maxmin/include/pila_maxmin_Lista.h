/**
 * @file pila_max_lista.h
 * @brief Fichero cabecera del TDA Pila_max usando la clase lista
 **/

#ifndef __PILA_MAX__
#define __PILA_MAX__

#include <iostream>
#include <lista.h>

using namespace std ;

class Pila_maxmin{

 private:
  /**
   * @brief Rep de Pila_max
   * Los elementos se almacenan en una lista del tipo "elemento" ; 
   * no hay invariante de representación ya que la implementación
   * en sí se da en la clase lista
   **/

  Lista<elemento> datos ;

 public:

  /**
   * @brief Indica si la pila está vacía 
   * @return true si la pila está vacía
   * @return false si la pila contiene al menos un elemento
   **/

  bool vacia() const{
    return (datos.size() == 0) ; 
  }

  /**
   * @brief Añade un elemento al final de la cola 
   * @param elem Elemento a añadir. 
   **/

  void poner(int elem) ;

  /**
   * @brief Elimina un elemento al final de la cola 
   **/

  void quitar() ;

  /**
   * @brief Devuelve el número de elementos de la cola
   **/
  int num_elem() const{
    return datos.size() ; 
  }

  /**
   * @brief Devuelve el último elemento de la pila 
   * @return un elemento (el último de la pila) 
   **/
  elemento tope() ;

} ;

#include <pila_maxmin_Lista.cpp>


#endif


