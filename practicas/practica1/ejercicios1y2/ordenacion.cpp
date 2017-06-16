#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

class VectorDinamico{
private:
  int *v ;
  int total_utilizados ;
  int vmax = 9 ;
  
public:

  VectorDinamico(int size, int max){
    total_utilizados = size ;
    v = new int[total_utilizados] ;
    vmax = max  ;
  }

  ~VectorDinamico(){
    delete [] v ;
  }
  

  void Inicializar(){
    int *v = new int[total_utilizados] ;
    srand(time(0)) ;
    for(int i = 0 ; i < total_utilizados ; i++)
      v[i] = rand() % vmax ; 
  }

  void Intercambia(int a, int b){
      int aux = v[b] ;
      v[b] = v[a] ;
      v[a] = aux ;
    }

    void Mostrar(){
      for(int a = 0 ; a < total_utilizados ; a++)
	cout << "[" << v[a] << "]" ;
      cout << endl ; 
    }

  void ordena_Burbuja(){
    for(int i = 0 ; i < total_utilizados-1 ; i++)
      for(int j = 0 ; j < total_utilizados-1-i ; j++)
	if(v[j] > v[j+1]){
	    int aux = v[j] ;
	    v[j] = v[j+1] ;
	    v[j+1] = aux ;
	  }
  }

  int BusquedaSecuencial(int buscado) {

    bool encontrado = false ;
    int pos_encontrado ;

    for(int i = 0 ; i< total_utilizados && !encontrado ; i++){
      // Mostrar() ; 
      if(encontrado = buscado == v[i] )
	pos_encontrado = v[i] ;
    }

    if(encontrado)
      return pos_encontrado ;
    else
      return -1 ;
  }
  
} ;

 void sintaxis() {
cerr << "Sintaxis:" << endl;
cerr << " TAM: Tamaño del vector (>0)" << endl;
cerr << " VMAX: Valor máximo (>0)" << endl;
cerr << "Genera un vector de TAM números aleatorios en [0,VMAX[" << endl;
exit(EXIT_FAILURE);
}

  
int main(int argc, char *argv[])
{
  if(argc != 3)
   sintaxis() ;
  int tam = atoi(argv[1]) ;
  int vmax = atoi(argv[2]) ;

  VectorDinamico *vector = new VectorDinamico(tam, vmax) ;

  vector->Inicializar() ;

  
  clock_t tini ;
  tini=clock() ;

  vector->ordena_Burbuja() ;

  clock_t tfin = clock() ; 
  

  cout << tam << "\t" << (tfin - tini ) / (double)CLOCKS_PER_SEC << endl ;

  
    
  return 0;
}

      

      

    
