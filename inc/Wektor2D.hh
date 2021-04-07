#ifndef WEKTOR2D_HH
#define WEKTOR2D_HH
#include <iostream>
#include "Macierz2x2.hh"

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
#define SIZEV 2


class Vect {
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
  
  public:
  double tabw [SIZEV];
  double operator () (int Ind) const { return tabw[Ind]; };
  // friend std::ostream& operator << ( std::ostream &stream, const Vect &vec);
  friend std::istream& operator >> ( std::istream &stream, Vect &vec);
  Vect operator + ( Vect vec2);
  Vect operator - ( Vect vec2);
  Vect operator * ( Macierz2x2 &matrix);
  friend std::ostream& operator << ( std::ostream &stream, const Vect &A); 
};


#endif
