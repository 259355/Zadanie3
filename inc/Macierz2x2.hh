#ifndef MACIERZ2X2_HH
#define MACIERZ2X2_HH
#include <math.h>
#include <iostream>


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
#define SIZEM 2

class Macierz2x2 {
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
  
  double tab[SIZEM][SIZEM];

  public:
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */    
  double& operator () (int Lin, int Col) { return tab[Lin][Col]; }
  friend std::ostream& operator << (std::ostream &Strm, const Macierz2x2 &Mac);
  double angle; 
  // double tab[SIZEM][SIZEM];
  Macierz2x2 Init();
  double toradians();
  // void turn(Prostokat pr, int ang);
};


#endif
