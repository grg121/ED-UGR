
/**
 * @file Frase.h
 * @brief Fichero cabecera del TDA Frase
 *
 */

#ifndef __FRASE
#define __FRASE

#include<iostream>
#include<vector>

using namespace std;




/**
 * @brief T.D.A Frase
 * Una instancia @e c del tipo de datos abstracto @c Frase es un objeto de un conjunto de pares de frases:
 * frase_idioma_origen - frase_idioma_destino que sirve para traducir la frase del idioma de origen al
 * idioma de destino.
 *
 * @autor F. Navarro Morales
 * @date Octubre 2016 
 */

class Frase {
 private:
  /**
   * @page repConjunto Rep del TDA Frase
   *
   * @section invConjunto Invariante de la representación
   * El invariante es r.traducciones.size() > 0
   *
   * @section faConjunto función de abstracción
   *
   * Un objeto válido @e rep del TDA Frase representa al valor:
   * f(r)={	r.frases[0].origen	;	r.frases.traducciones[0]	;	......	;
   * r.frases.traducciones[traducciones.size()]
   *
   */

  string origen ;

 std:vector<string> traducciones ;


 public:
  
  /**
   * @brief Constructor por defecto de la clase.
   */
  Frase(string original = ""){
    origen = original ;
  }

  /**
   * @brief Getter de origen
   **/

  string getOrigen() const { return origen ;  } ;
  

  std::vector<string> GetDestino() const {
    return traducciones ;
  }

  /**
   * @return Devuelve el número de traducciones de la frase original.
   */
  int n_trad(){ return traducciones.size() ;  }

  /**
   * @brief sobrecarga del operador =
   * @param f frase que asignar a this
   * @return frase asignada 
   **/ 
  Frase& operator=(const Frase &f) ; 


  /**
   * @brief añadir una nueva traducción 
   * @param 
   **/
  void InsertarTraduccion(string traduccion) ;

  /**
   * @brief salida de una frase
   * @param os stream de salida 
   * @param f frase que sale por el flujo os
   **/
  friend ostream& operator<<(ostream& os, Frase &f) ; 

} ; 

#endif
  
