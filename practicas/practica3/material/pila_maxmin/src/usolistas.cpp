#include <iostream>
#include <lista.h>
#include <string> 

using namespace std;

int main(){

  Lista<std::string> l ;

  Lista<std::string>::iterator itb, ite ;

  itb = l.begin() ;

  std::string s = "*" ; 

  for(int i = 0 ; i < 15 ; i++, itb = l.begin(), ite = l.end()){
    for(int j = 0 ; j < i ; j++)
      s = s + "*" ; 
    l.Insertar(itb, s) ;
    l.Insertar(ite, s) ;
  }
 
  Lista<std::string>::iterator it ;

    Lista<std::string> l2 ;

  l2 = l ;

  for( it = l2.begin() ; it != l2.end() ; ++it){
    cout << *it <<endl ;
  }

  cout << " ------------------------------ " << endl ;

  Lista<int> l3 ;
  Lista<int>::iterator int_it ; 

  int_it = l3.begin() ;

  l3.Insertar(int_it, 5) ;

  --int_it ; 

  cout << *int_it ; 


  
}
