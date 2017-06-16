/**
 * @file ConjuntoFrases.h
 * @brief Fichero cabecera del TDA ConjuntoFrases
 *
 */

#ifndef __CONJUNTOFRASES
#define __CONJUNTOFRASES

#include<iostream>
#include <vector> 


/**
 * @brief T.D.A ConjuntoFrases
 * Una instancia @e c del ripo de datos abstraco @c ConjuntoFrases es un objeto de un conjunto de objetos del TDA
 * Frase tal que caa frase no aparece más de una vez (ni siquiera con distintas traducciones)
 */

class ConjuntoFrases{
 private:
  /**
   * @page repConjunto Rep del TDA ConjuntoFrase
   *
   * @section invCOnjunto Invaruante de la representación.
   *
   * El invariante es:
   * para todo i,j r.frases[i].origen != r.frases[j].origen ;
   *
   * @section faConjunto función de abstracción:
   *
   * Un objeto válido @e rep del TDA ConjuntoFrase representa al valor:
   *
   * 
   * f(r)={	r.frases[0].origen	;	r.frases.traducciones[0]	;	......	;
   * r.frases.traducciones[traducciones.size()]
   * .............
   * ..............
   * r.frases[frases.size()].origen	;	r.frases[frases.size()].traducciones[0]	;	.....
   * r.frases[frases.size()].traducciones[traducciones[size()]]	}
   */

  std::vector<string> frases ;

 public:



  /**
   * @brief Devuelve el número de frases disponibles 
   * @return número de frases disponibles 
   **/
  int Size(){ return frases.size() ;  } 


  /**
   * @brief comprueba si la frase daa está en el conjunto
   */
  bool Esta(const string &frase);

  /**
   * @brief añadir una nueva frase
   */

  void Insertar(string const frase){
    Frase nueva(frase) ; 
    this->frases.insert(nueva) ; 
      }
  

    /**
   * @brief salida de un conjunto de frases a ostream
   * @param os stream de salida
   * @param c ConjuntoFrase a escribir
   * @retval Se escriben las frases en el idioma de origen y sus traducciones.
   */
  friend ostream& operator<<(ostream& os, const ConjuntoFrases& cf) ;


  /**
   * @brief Entrada de un ConjuntoFrase desde istream
   * @param is stream de entrada
   * @param c Conjunto que recibe el valor de entrada
   * @retval Las frases leídas en c
   * @pre La entrada tiene el formato "frase_original ; frase_traducida \n " para
   * cada frase que se añada al conjunto.
   */

    friend istream& operator>> (istream& is, ConjuntoFrases& cf) ;

    /**
   * @brief Devuelve las traducciones de la frase origen ff
   * @return un vector dinámico con las traducciones de la frase origen dada
   * @param ff: frase origen a traducir
   **/
   Frase GetTraducciones( const string & ff) ;

   /**
    * @brief Busca la posición en la que se encuentra la frase dada
    * @return la posición donde se encuentra la frase dada 
    * @param frase: la frase a buscar
    **/

   int Busca(const string& frase) ;

   ConjuntoFrases Contenga(const string subcadena) ; 
} ;




#endif
