// Pila_maxmin.h


using namespace std; 
/**
 * @brief TDA Elemento
 *
 * Es un contenedor donde se almacenan los valores contenidos 
 * en la pila, además del mayor y el menor valor que hay contenido
 * en la pila por debajo de este (incluyéndolo) 
 **/

struct  elemento{
  int ele ; ///<elemento a almacenar
  int maximo ; //<elemento máximo hasta el momento
  int minimo; //<elemento mínimo hasta el momento

	friend ostream& operator<<(ostream &os, const elemento& e){
		os << e.ele << " (" << e.maximo << "," << e.minimo << ") " << endl ; 
		return os ;; 
	} ; 
} ; 

#define CUAL_COMPILA 3

#if CUAL_COMPILA==1
#include<pila_maxmin_VD.h>
#elif CUAL_COMPILA==2
#include<pila_maxmin_Lista.h>
#else
#include<pila_maxmin_Cola.h>
#endif
