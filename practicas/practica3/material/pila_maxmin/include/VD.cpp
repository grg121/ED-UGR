//VD.cpp

template<class T>
VD<T>::VD(int tam){
  n = 0 ;
  reservados = 10 ;
  datos = new T[reservados] ; 
}

template<class T>
void VD<T>::resize(int nuevotam){
  T *aux = new T[nuevotam] ;
  int minimo = (n<nuevotam)?n:nuevotam ;
  for(int i = 0 ; i < minimo ; i++)
    aux[i] = datos[i] ;
  reservados = nuevotam ;
  n = minimo ;
  delete [] datos ;
  datos = aux ;

}

template <class T>
void VD<T>::Copiar(const VD<T> &v){
  reservados = v.reservados ;
  n = v.n ;
  datos = new T[reservados] ;
  for(int i = 0 ; i < n ; i++)
    datos[i] = v.datos[i] ;

}

template <class T>
void VD<T>::Liberar(){ delete [] datos ; }



template <class T>
VD<T>::VD(const VD<T> &original){
  Copiar(original) ; 
}

template <class T >
VD<T>::~VD(){
  Liberar() ; 
}

template <class T>
VD<T> & VD<T>::operator=(const VD<T> & v){
  if(this != &v){
    Liberar() ;
    Copiar(v) ; 
  }
  return *this ;
}

template <class T>
void VD<T>::Insertar(const T &d, int pos){
  if( n >= (reservados/2))
    resize(2*reservados) ;
  for(int i = n ; i > pos ; i--)
    datos[i] = datos[i-1] ;
  datos[pos] = d;
  n++ ;
}

template<class T>
void VD<T>::Borrar(int pos){
  for(int i = pos ; i < n-1 ; i++)
    datos[i] = datos[i+1] ;
    n-- ;
    if(n<(reservados/4))
      resize(reservados/2) ;

}

template<class T>
bool VD<T>::buscar( T& elemento){
  bool salida = false ; 
  for(unsigned i = 0 ; i < size() && !salida ; i++){
    salida = elemento == datos[i] ;
  }
  return salida ;
}


