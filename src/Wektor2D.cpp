#include "Wektor2D.hh"
#include <iomanip>
#include <math.h>



/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Wektor2D, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

// std::ostream& operator << ( std::ostream &stream, const Vect &vec){
//     stream << std::setprecision(1);
//     stream << "[" << vec.tabw[0] << "," << vec.tabw[1] << "]" << std::endl;
//     return stream;
// }

std::istream & operator >> ( std::istream &stream, Vect &vec){
    char tmp;

    stream >> tmp;

    if (stream.fail())
        return stream;
    
    if(tmp != '['){
        stream.setstate(std::ios::failbit);
        return stream;
    }
    
    stream >> vec.tabw[0];
    
    if(!stream){
        stream.setstate(std::ios::failbit);
        return stream;
    }

    stream >> tmp;

    if (stream.fail())
        return stream;
    
    if(tmp != ','){
        stream.setstate(std::ios::failbit);
        return stream;
    }

    stream >> vec.tabw[1];
    
    if(!stream){
        stream.setstate(std::ios::failbit);
        return stream;
    }

    stream >> tmp;

    if (stream.fail())
        return stream;
    
    if(tmp != ']'){
        stream.setstate(std::ios::failbit);
        return stream;
    }

    return stream; 

}

Vect Vect::operator + (Vect vec2){
    Vect tempvec;

    tempvec.tabw[0] = this->tabw[0] + vec2.tabw[0];
    tempvec.tabw[1] = this->tabw[1] + vec2.tabw[1];

    return tempvec;
}

double Vect::blenght (Vect vec2){
    double bigl;
    double smalll;
    
    bigl = sqrt(pow(vec2.tabw[0] - this->tabw[0],2) + pow(vec2.tabw[1] - this->tabw[1],2));

    return bigl;
}

double Vect::slenght (Vect vec2){

    double smalll;
    
    smalll = sqrt(pow(vec2.tabw[0] - this->tabw[0],2) + pow(vec2.tabw[1] - this->tabw[1],2));

    return smalll;
}

Vect Vect::operator - (Vect vec2){
    Vect tempvec;

    tempvec.tabw[0] = this->tabw[0] - vec2.tabw[0];
    tempvec.tabw[1] = this->tabw[1] - vec2.tabw[1];

    return tempvec;
}

std::ostream& operator << ( std::ostream &stream, const Vect &A){

    stream << std::setw(16) << std::fixed << std::setprecision(10) << A.tabw[0]
           << std::setw(16) << std::fixed << std::setprecision(10) << A.tabw[1] << std::endl; 

    return stream;
}

Vect Vect::operator * (Macierz2x2 &matrix){
    double temp;
    temp = this->tabw[0];
    this->tabw[0] = this->tabw[0] * matrix.tab[0][0] + this->tabw[1] * matrix.tab[0][1];    
    this->tabw[1] = temp * matrix.tab[1][0] + this->tabw[1] * matrix.tab[1][1];
    return *this;
}