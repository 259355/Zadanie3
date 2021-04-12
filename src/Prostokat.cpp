#include "Prostokat.hh"

#include <iomanip>

#define MIN_DIFF 0.0000001

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

double Prostokat::lenght(){
    
   this->slen = this->p1.vlenght(this->p2);
   this->blen = this->p2.vlenght(this->p3);
   return 0;
}


std::ostream& operator << ( std::ostream &stream, const Prostokat &Pr){

    stream << Pr.p1 << std::endl;
    stream << Pr.p2 << std::endl;
    stream << Pr.p3 << std::endl;
    stream << Pr.p4 << std::endl;
    stream << Pr.p1 << std::endl;

    return stream;
}




void Prostokat::showres(double temp1, double temp2){

    if(temp2 == this->slen){
       std::cout << ":) Shorter sides are equal." << std::endl;
       std::cout << "Before operation: " << temp2 << std::endl;
       std::cout << "After operation: " << this->slen << std::endl;
   } 
   else{
       std::cout << ":( Shorter sides are not equal." << std::endl;
       std::cout << "Before operation: " << temp2 << std::endl;
       std::cout << "After operation: " << this->slen << std::endl; 
   }
   std::cout << std::endl;
   if(temp1 == this->blen){
       std::cout << ":) Longer sides are equal." << std::endl;
       std::cout << "Before operation: " << temp1 << std::endl;
       std::cout << "After operation: " << this->blen << std::endl;
   } 
   else{
       std::cout << ":( Longer sides are not equal." << std::endl;
       std::cout << "Before operation: " << temp2 << std::endl;
       std::cout << "After operation: " << this->blen << std::endl; 
   }

}


void Prostokat::turn(int ang){
    Macierz2x2 matrix;
    matrix.angle = ang;
    matrix.toradians();
    matrix.Init();
    *this = *this * matrix;

}