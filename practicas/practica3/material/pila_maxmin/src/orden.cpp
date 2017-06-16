#include<iostream>
#include "pila_maxmin.h"
#include<fstream> 
using namespace std;
struct mypair {
  int first ;
  int second ;
} ; 

bool menor(Pila_maxmin primera, Pila_maxmin segunda){
  return (primera.tope().maximo < segunda.tope().minimo) ;
}

bool contiene(Pila_maxmin primera, Pila_maxmin segunda, mypair & par){

  int max = primera.tope().maximo ;
  int min = primera.tope().minimo ;

  while(!segunda.vacia()){
    if( min < segunda.tope().minimo && max > segunda.tope().maximo){
      par.first = segunda.tope().minimo  ;
      par.second = segunda.tope().maximo ; 
      return true ;
    } segunda.quitar() ; 
  }
  return false ;
}

int main(int argc, char * argv[]){


  Pila_maxmin primera ;
  Pila_maxmin segunda ;

  if(argc >=2){
  std::ifstream imput1(argv[1]) ;
  std::ifstream imput2(argv[2]) ; 

  int data ; 

  cout << endl <<  " ----------------------------------- "  << endl
       << "Primer Conjunto: " << endl << endl ; 
  
  while(imput1 >> data){
    primera.poner(data) ;
    cout << primera.tope() ;
  }

  cout << endl <<  " ----------------------------------- "  << endl
       << "Segundo Conjunto: " << endl << endl  ; 
  while(imput2 >> data){ 
    segunda.poner(data) ;
    cout << segunda.tope() ;
  }

  cout << endl << " --- datos leídos corréctamente   --- " <<  endl << endl ;


  if(menor(primera, segunda))
    cout << "\nEl primer conjunto es menor que el segundo" << endl  ; 
  else if ( menor ( segunda, primera ) )
    cout << "\nEl segundo conjunto es menor que el primero" << endl  ;
  else
    cout << "\nNinguno de los conjuntos es mayor/menor que el otro" << endl ;

  
 mypair par ;

  if ( contiene ( primera, segunda, par )){
      cout << "El primer conjunto contiene al rango de valores ["
       << par.first << ", " << par.second << "] del segundo. "  ;
    }
  else if ( contiene (segunda, primera, par )) {
      cout << "El segundo conjunto contiene al rango de valores ["
       << par.first << ", " << par.second << "] del primero. "  ;
      }
  else cout << "\nNinguno de los conjuntos contiene algún rango de valores del otro\n" ; 
  }
  return 1 ; 
}
      
      

      
           
