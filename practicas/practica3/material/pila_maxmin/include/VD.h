#ifndef __VD
#define __VD


/**
 * @brief T.D.A Vector dinámico
 * Una instancia @e c del tipo de datos abstracto @c VD es una estructura lineal de datos del tipo T ( clase plantilla) con las operaciones necesarias para trabajar con ellos.
 *
 * @author F. Navarro Morales
 * @date Octubre 2016 
 */

template <class T>
class VD{
 private:

  T *datos ; ///< Puntero al comienzo del vector dinámico 
  int n ; ///< Número de datos alojados en el vector dinámico
  int reservados ; ///< Posiciones reservadas para elementos

  /**
   * @brief Modifica el número de posiciones reservadas 
   * @param nuevotam Nuevo número de posiciones reservadas
   */
  void resize(int nuevotam);

  /**
   * @brief Realiza una copia del vector dado como argumento
   * @param v vector a copiar en este. 
   */

  void Copiar(const VD<T> &v);

  /**
   * @brief Libera la memoria dinámica asociada al vector dinamico
   */
  
  void Liberar();
 public:
  /**
   * @brief Constructor por defecto con parámetro
   * @param tam: elementos a reservar para el vector dinámico
   * @note si no se proporciona un valor, toma 10 por defecto.
   */

  VD(int tam = 10) ;

  /**
   * @brief Constructor de copia
   * @param original: vector dinamico de origen
   */

  VD(const VD<T> &original) ;

  /**
   * @brief Destructor: elimina la memoria asociada al VD
   */
  ~VD();

  /**
   * @brief Operador de asignación
   * @param v: vector dinámico fuente
   * @return una ferencia al objeto al que apunta this
   */
  VD<T> &operator=(const VD<T> &v);
  /**
   * @brief Obtiene el número de elementos almacenados en el vector dinámico.
   */
  unsigned size() const { return (unsigned)n ; }

  /**
   * @brief Consulta y modifica el elemento i-esimo
   * @param i: posición del elemento
   * @return una referencia al elemento i-esimo del vector dinamico
   */

   T &operator[](int i){ return datos[i] ;}

   /**
    * @brief Operador [] (accede a un elemento del vector) 
    */
   
   const T &operator[](int i) const {return datos[i] ;}

   /**
    * @brief Inserta un objeto en la posición pos del VD.
    * @param d: objeto a insertar
    * @param pos: posición donde insertar
    * @pre pos debe estar comprendido entre 0 y size()
    * @post aumenta en uno el vector dinámico
    */
   void Insertar(const T &d, int pos);

   /**
    * @brief Elimina el elemento en la posición post
    * @param pos: posición del elemento a borrar.
    */

    void Borrar(int pos) ;

   /**
    * @brief Comprueba si un elemento está en el vector
    * @param elemento elemento a buscar en el vector
    * @return true si el elemento se encuentra en el vector
    * @return false si el elemento no se encuentra en el vector
    */
   
   bool buscar( T& elemento) ; 

} ;


#include "VD.cpp"



#endif 
