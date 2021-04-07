#ifndef PROSTOKAT_HH
#define PROSTOKAT_HH

#include "Macierz2x2.hh"
#include "Wektor2D.hh"
#include <iostream>


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */

// class Point{
//   public:
//     double x;
//     double y;
//     friend Point operator * (Point &A, Macierz2x2 &matrix);
//     friend Point operator + (Point &A, Vect &vec);
//     friend std::ostream& operator << ( std::ostream &stream, const Point &A);
//   };

class Prostokat {
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
  public:
  Vect p1;
  Vect p2;
  Vect p3;
  Vect p4;
  double blen;
  double slen;
  
  Prostokat operator + (Vect vec2);
  void turn(int ang);
  double slenght();
  double blenght();
  Prostokat operator * (Macierz2x2 &matrix);
  Prostokat move(Vect &vec);
  friend std::ostream& operator << ( std::ostream &stream, const Prostokat &Pr);
  // friend std::ostream& operator << ( std::ostream &stream, const Point &A);
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */  
};



#endif
