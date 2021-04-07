#include "Prostokat.hh"

#include <iomanip>

/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Prostokat, ktore zawieraja 
 *  wiecej kodu niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

Prostokat Prostokat::operator * (Macierz2x2 &matrix){
    this->p1 = this->p1 * matrix ;
    this->p2 = this->p2 * matrix ;
    this->p3 = this->p3 * matrix ;
    this->p4 = this->p4 * matrix ;

    return *this;
}


Prostokat Prostokat::move(Vect &vec){
    this->p1 = this->p1 + vec;
    this->p2 = this->p2 + vec;
    this->p3 = this->p3 + vec;
    this->p4 = this->p4 + vec;

    return *this;
}

double Prostokat::blenght(){
    
   this->blen = this->p1.blenght(this->p2);
   
   return this->blen;
}

double Prostokat::slenght(){
    
   this->slen = this->p1.slenght(this->p2);
   
   return this->slen;
}

std::ostream& operator << ( std::ostream &stream, const Prostokat &Pr){
    // stream << std::setprecision(7);
    stream << Pr.p1 << std::endl;
    stream << Pr.p2 << std::endl;
    stream << Pr.p3 << std::endl;
    stream << Pr.p4 << std::endl;
    // stream << Pr.p1 << std::endl;
    // stream << std::setw(16) << std::fixed << std::setprecision(10) << Pr.p1 << std::endl;
    //         // << std::setw(16) << std::fixed << std::setprecision(10) << y1+Przesuniecie << std::endl;
    // stream << std::setw(16) << std::fixed << std::setprecision(10) << Pr.p2 << std::endl; 
    //         // << std::setw(16) << std::fixed << std::setprecision(10) << y2+Przesuniecie << std::endl;
    // stream << std::setw(16) << std::fixed << std::setprecision(10) << Pr.p3 << std::endl; 
    //         // << std::setw(16) << std::fixed << std::setprecision(10) << y3+Przesuniecie << std::endl;
    // stream << std::setw(16) << std::fixed << std::setprecision(10) << Pr.p4 << std::endl; 
    //         // << std::setw(16) << std::fixed << std::setprecision(10) << y4+Przesuniecie << std::endl;
    // stream << std::setw(16) << std::fixed << std::setprecision(10) << Pr.p1 << std::endl; 
    //         // << std::setw(16) << std::fixed << std::setprecision(10) << y1+Przesuniecie << std::endl; 
    return stream;
}

void Prostokat::turn(int ang){
    Macierz2x2 matrix;
    matrix.angle = ang;
    matrix.toradians();
    matrix.Init();
    *this = *this * matrix;

}