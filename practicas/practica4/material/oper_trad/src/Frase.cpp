#include<iostream>
#include"Frase.h"
using namespace std;


// Sobrecarga del operador de asignación
Frase& Frase::operator=(const Frase &f){
  traducciones = f.traducciones ;
  origen = f.origen ; 
  // utiliza la sobrecarga del operador de asignación de la clase VD
  return * this ; 
}

void Frase::InsertarTraduccion(string traduccion){
    bool ya_esta = false ;
    for(unsigned i = 0 ; !ya_esta && i < traducciones.size() ; i++)
      ya_esta = traducciones[i] == traduccion ;
      if(!ya_esta)
	traducciones.insert(traduccion) ;
    
}
    
     ostream& operator<<(ostream& os, Frase& f){
       os << f.getOrigen() ;
       os << "\n\t" ;
       for(unsigned i = 0 ; i < f.traducciones.size() ; i++){
	 os << f.GetDestino()[i] << "\n\t" ;
      } os << endl ;
       return os ; 
    }


    
