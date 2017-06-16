template <class T>
void Lista<T>::Insertar(Lista<T>::iterator it, const T & e) {

  if(it.punt == NULL){
    it.punt = new Celda(e, it.punt, it.punt) ;
  }else{
  
  Celda *aux = new Celda ;
  aux->elemento = e ;
  aux->siguiente = it.punt ;

  aux->anterior = it.punt->anterior ;
  it.punt->anterior->siguiente = aux ;
  it.punt->anterior = aux ;
  }

}
template <class T>
void Lista<T>::Borrar ( Lista<T>::iterator it ){
  it.punt->anterior->siguiente = it.punt->siguiente ;
  it.punt->siguiente->anterior = it.punt->anterior ;

  delete it.punt ;
}

template <class T>
Lista<T>& Lista<T>::operator=(const Lista<T> &l){
  Lista<T>::const_iterator copy = l.begin() ;
  Lista<T>::iterator it_this = begin() ;

  while(it_this != end()){
    Borrar(it_this) ;
  }
  
  while(copy != l.end()){
    Insertar(it_this,*copy) ;
    ++copy ;
  }
  return *this ; 
}
    

