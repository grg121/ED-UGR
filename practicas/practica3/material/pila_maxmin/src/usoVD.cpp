#include<iostream>
#include<VD.h>

using namespace std;

int main(){

  VD<int> vector ;

  for(unsigned i = 0 ; i < 15 ; i++)
    vector.Insertar(i, vector.size()) ;

  int j = 3 ; 

  vector.buscar(j) ;
  
  cout << "\nEl 4 está\n" ;

  vector[2] = 0 ;

  for(unsigned i = 0 ; i < vector.size() ; i++)
    cout << vector[i] << endl  ;

  cout << " ------------------ " << endl ;

  while(vector.size() > 1){
    vector.Borrar(vector.size()-1) ; 
  
    cout << "tam: " << vector.size() << endl ;
    cout << "ultima: " << vector[vector.size()-1] << endl ;
    cout << "primera: "  << vector[0] << endl ;

  }
}

  

  
