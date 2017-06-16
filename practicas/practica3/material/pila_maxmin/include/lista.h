/**
 * @file lista.h
 * @brief Fichero cabecera del TDA Lista
 *
 * Gestiona una secuencia de elementos con facilidades para la insercción, 
 * borrado y consultas desde cualquier posición .
 */

#ifndef __LISTA_H__
#define __LISTA_H__

#include <cassert>

/**
 * @brief T.D.A Lista
 *
 *
 * Una instancia @e c del tipo de dato abstracto Lista sobre un dominio @e T es
 * una sucesión finita de elementos del mismo de forma tal que dichos elementos
 * pueden ser insertados, eliminados o consultados independientemente de la 
 * posición que ocupen en la lista. 
 *
 * Una lista de longitud n la denotaremos: { a0, a1, .... , an }
 *
 * Si n = 0 diremos que la lista está vacía. 
 *
 * @author Francisco Navarro 
 * @date 2016 ( Noviembre ) 
 */

template <class T>
class Lista{
 private:
  struct Celda {
    T elemento ;
    Celda * siguiente ; ///< Puntero a la celda siguiente en la lista.
    Celda * anterior ; ///< Puntero a la celda anterior en la lista.
    /**
     * @brief Constructor por defecto 
     */
  Celda() : siguiente(0), anterior(0){} 

    /**
     * @brief Constructor con parámetros.
     * @param elem Elemento de información.
     * @param sig Puntero a la celda siguiente.
     */
  Celda(const T & elem, Celda * sig, Celda * ant) : elemento(elem), siguiente(sig), anterior(ant){}  
  } ;

  Celda * cabecera ; ///< Puntero a la cabecera de la lista (Begin.anterior) 

 public:

  //--------------------- CONSTRUCTORES ---------------------

  /**
   * @brief Constructor por defecto
   */ 
  Lista(){
    cabecera = new Celda ;
    cabecera->siguiente = cabecera ;
    cabecera->anterior = cabecera ; 
  } ;

  /**
   * @brief Constructor de copia 
   * @param l La lista de la que se hará la copia   */
  Lista(const Lista &l) ;

  // --------------------- DESTRCUTOR -----------------------

  /**
   * @brief Destructor
   */
  ~Lista(){
    while(cabecera->siguiente != cabecera->anterior && cabecera->siguiente != cabecera){
      Celda *aux = new Celda ;
      aux = cabecera->siguiente ;
      cabecera->siguiente->siguiente->anterior = cabecera ;
      cabecera->siguiente = cabecera->siguiente->siguiente ;
      delete aux ; 
    }

  }
  ;

  //-------------- OTRAS FUNCIONES ---------------------------

  /**
   * @brief Operador de asignación. 
   * @param l Lista que asignar. 
   **/

  Lista & operator= (const Lista<T> &l) ;


  class const_iterator ;

  class iterator{
  private:
    Celda *punt ;
  public:
  iterator(): punt(0){}
    iterator& operator++(){
      punt = punt->siguiente;
      return *this ;
    }

    iterator& operator-- (){
      punt = punt->anterior ;
      return *this ;
    }

    T & operator* () { return punt->elemento ; }

    bool operator== (const iterator &i ) const {
      return punt==i.punt ;
    }

    bool operator != (const iterator &i) const{
      return punt!=i.punt ;
    }


    friend class Lista ;
    friend class const_iterator ;
  } ;

  class const_iterator {
  private:
    Celda *punt ;
  public:
    const_iterator(const iterator &i){
      punt=i.punt ;
    }
    const_iterator(Celda *puntero){
      punt = puntero ;
    }

    bool operator== (const const_iterator &i) const{
      return punt==i.punt ;
    }
    bool operator!= (const const_iterator &i) const{
      return punt!= i.punt ;
    }

    const T & operator* () const {
      return punt->elemento ;
    }

    const_iterator & operator++ () {
      punt = punt->siguiente ;
      return *this ;
    }

    const_iterator & operator-- (){
      punt = punt->anterior ;
      return *this ;
    }

    friend class Lista ;
  } ;
  

  /**
   * @brief Inserción de un elemento en una posición
   * @pram p Posición donde insertar el elemento
   * @param e Elemento a insertar 
   */
  
  void Insertar(iterator it,const  T &e) ;

  /**
   * @brief Eliminar un elemento de la posición dada
   * @param p Posición en la que eliminar el elemento
   */
  void  Borrar(iterator it) ;

  /**
   * @brief Número de elementos de la Lista
   */
  int size() const{
    const_iterator it(begin()) ;
    int count = 0 ;
    while(it != end()){
      ++it ;
      count++ ;
    }
    return count ;
  }

  /**
   * @brief Devuelve el primer elemento de la lista
   * @return el primer elemento de la lista.
   */ 
  iterator begin() {
    iterator it ; 
    it.punt = cabecera->siguiente ;
    return it ;
  }

  /**
   * @brief Devuelve la posición siguiente al último elemento de la lista
   * @return posición del final de la lista
   */

  iterator end(){
    iterator it;
    it.punt = cabecera ;
    return it ;
  }

    /**
   * @brief Devuelve el primer elemento de la lista
   * @return el primer elemento de la lista.
   */ 
  const_iterator begin() const {
    const_iterator it(cabecera->siguiente) ;
    return it ;
  }

    /**
   * @brief Devuelve la posición siguiente al último elemento de la lista
   * @return posición del final de la lista
   */

  const_iterator end() const {
    const_iterator it(cabecera) ;
    return it ;
  }


};

#include<lista.cpp>
#endif // __Cola_H__
  
