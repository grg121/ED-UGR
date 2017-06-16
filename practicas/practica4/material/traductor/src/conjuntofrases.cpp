#include<iostream>
using namespace std ;
#include"conjuntofrases.h"
#include"Frase.h"
#include <assert.h>
#include <stdio.h>
#include <ctype.h>

bool iequals(const string& a, const string& b)
{
    unsigned int sz = a.size();
    if (b.size() != sz)
        return false;
    for (unsigned int i = 0; i < sz; ++i)
        if (tolower(a[i]) != tolower(b[i]))
            return false;
    return true;
}


Frase ConjuntoFrases::GetTraducciones( const string &frase ){
    assert(Esta(frase)) ;
    Frase salida ;
    for(unsigned i = 0 ; i < frases.size() ; i++)
        if(iequals(frases[i].getOrigen(), frase))
            salida = frases[i] ;
    return salida ;
}

bool ConjuntoFrases::Esta(const string &frase){
    int esta = Busca(frase) ;
    if(esta != -1)
        return true;
    else
        return false ;
}


int ConjuntoFrases::Busca(const string &frase){
    bool esta = false ;
    unsigned salida = 0 ;
    int izda, dcha;
    izda = 0 ; dcha = frases.size() - 1 ;
    salida = (izda + dcha)/2 ;

    while(izd.a <= dcha && ! esta){
        esta = frases[salida].getOrigen() == frase ;
        if(!esta){
            if (frase < frases[salida].getOrigen() )
                dcha = salida - 1 ;
            else izda = salida + 1 ;
        }
        salida = (izda+dcha)/2 ;
    }
    if(esta)
        return salida ;
    else
        return -1 ;
}




ConjuntoFrases ConjuntoFrases::Contenga(const string subcadena){
    ConjuntoFrases nuevo ;
    for(unsigned i = 0 ; i < this->frases.size() ; i++){
        std::size_t found = this->frases[i].getOrigen().find(subcadena);
        if (found!=std::string::npos)
	    nuevo.frases.Insertar(this->frases[i], nuevo.frases.size()) ;
    }return nuevo ;
}





ostream& operator<<(ostream& os, const ConjuntoFrases &cf){
    for(unsigned i = 0 ; i < cf.frases.size() ; i++){
        os << cf.frases[i].getOrigen() ;
        for( unsigned j = 0 ; j < cf.frases[i].GetDestino().size() ; j++)
            os << "\n\t" <<  cf.frases[i].GetDestino()[j] ;
        os << endl ;
    } return os ;
}





istream& operator>>(istream& is, ConjuntoFrases& cf){

    string delimitador = ";" ;

    string linea ;

    string original, traduccion ;

    while(std::getline(is,linea)){
        original = linea.substr(0, linea.find_first_of(delimitador) ) ;
        linea = linea.substr(linea.find_first_of(delimitador)+1) ;

        unsigned posicion = 0 ;

        if(!cf.Esta(original)){
            Frase nueva(original) ;
            while(cf.frases[posicion].getOrigen() <= original && posicion <= cf.frases.size())
                posicion++;
            cf.frases.Insertar(nueva, posicion) ;
        }
        else
            posicion = cf.Busca(original) ;

        traduccion = linea.substr(0, linea.find_first_of(delimitador) ) ;
        cf.frases[posicion].InsertarTraduccion(traduccion) ;
        while(linea != traduccion){
            traduccion = linea.substr(0, linea.find_first_of(delimitador) ) ;
            linea = linea.substr(linea.find_first_of(delimitador)+1) ;
            cf.frases[posicion].InsertarTraduccion(traduccion) ;
        }
    } return is ;
}
