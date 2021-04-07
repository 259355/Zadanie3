#include "Macierz2x2.hh"
#include <math.h>


/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Macierz2x2, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

Macierz2x2 Macierz2x2::Init(){

    
    this->tab[0][0] = cos(this->angle);
    this->tab[0][1] = -sin(this->angle);
    this->tab[1][0] = sin(this->angle);
    this->tab[1][1] = cos(this->angle);

    return *this;
}

double Macierz2x2::toradians(){

    this->angle = (this->angle * M_PI)/180;
    return this->angle;
}

std::ostream& operator << (std::ostream &stream, const Macierz2x2 &mtr){
    stream << "[cos(" << mtr.angle << "-sin(" << mtr.angle << ")]" << std::endl;
    stream << "[sin(" << mtr.angle << "cos( " << mtr.angle << ")]" << std::endl;
    return stream;
}
