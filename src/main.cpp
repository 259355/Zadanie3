#include <iostream>
#include <iomanip>
#include <fstream>
#include "Wektor2D.hh"
#include "Macierz2x2.hh"
#include "Prostokat.hh"
#include "lacze_do_gnuplota.hh"



using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */

#define DL_KROTKI_BOK  100
#define DL_DLUGI_BOK   150





/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do strumienia wyjściowego.
 * Dane sa odpowiednio sformatowane, tzn. przyjęto notację stałoprzecinkową
 * z dokładnością do 10 miejsca po przecinku. Szerokość wyświetlanego pola 
 * to 16 miejsc, sposób wyrównywania - do prawej strony.
 * \param[in] StrmWy - strumien wyjsciowy, do ktorego maja zostac zapisane
 *                     kolejne wspolrzedne.
 * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
 *                          mozliwosc zmiany wspolrzednych i prostokata
 *                          i zmiane jego polorzenia na okienku graficznym
 *                         rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
void PrzykladZapisuWspolrzednychDoStrumienia( ostream& StrmWy, Prostokat pro)
{
   //---------------------------------------------------------------
   // To tylko przyklad !!!
   // W programie nalezy uzywać pojęcia wektora, a nie oddzielnych 
   // zmiennych do reprezentowania wspolrzednych!
   //
//   double  x1, y1, x2, y2, x3, y3, x4, y4; 

//   x1 = y1 = 10;
//   x2 = x1 + DL_DLUGI_BOK;  y2 = y1;
//   x3 = x2;  y3 = y2 + DL_KROTKI_BOK;
//   x4 = x3 - DL_DLUGI_BOK; y4 = y3;


//   StrmWy << setw(16) << fixed << setprecision(10) << x1+Przesuniecie 
//          << setw(16) << fixed << setprecision(10) << y1+Przesuniecie << endl;
//   StrmWy << setw(16) << fixed << setprecision(10) << x2+Przesuniecie 
//          << setw(16) << fixed << setprecision(10) << y2+Przesuniecie << endl;
//   StrmWy << setw(16) << fixed << setprecision(10) << x3+Przesuniecie 
//          << setw(16) << fixed << setprecision(10) << y3+Przesuniecie << endl;
//   StrmWy << setw(16) << fixed << setprecision(10) << x4+Przesuniecie 
//          << setw(16) << fixed << setprecision(10) << y4+Przesuniecie << endl;
//   StrmWy << setw(16) << fixed << setprecision(10) << x1+Przesuniecie 
//          << setw(16) << fixed << setprecision(10) << y1+Przesuniecie << endl; 
//                              // Jeszcze raz zapisujemy pierwszy punkt,
//                              // aby gnuplot narysowal zamkniętą linię.
  // Prostokat pro;
  // pro.p1.tabw[0] = 100;
  // pro.p1.tabw[1] = 100;
  // pro.p2.tabw[0] = 100;
  // pro.p2.tabw[1] = 400;
  // pro.p3.tabw[0] = 700;
  // pro.p3.tabw[1] = 400;
  // pro.p4.tabw[0] = 700;
  // pro.p4.tabw[1] = 100;
//   StrmWy << pro << endl;
  // Macierz2x2 matr;
  int ang = 30;
  // Vect vec;
  // vec.tabw[0] = 100;
  // vec.tabw[1] = 100;
//   pro.move(vec);
  pro.turn(ang);
  StrmWy << pro << endl;
  // pro.slenght();
  // pro.blenght();
}



/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] sNazwaPliku - nazwa pliku, do którego zostana zapisane
 *                          wspolrzędne punktów.
 * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
 *                          mozliwosc zmiany wspolrzednych i prostokata
 *                          i zmiane jego polorzenia na okienku graficznym
 *                         rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool PrzykladZapisuWspolrzednychDoPliku( const char  *sNazwaPliku, Prostokat pro)
{
  ofstream  StrmPlikowy;

  StrmPlikowy.open(sNazwaPliku);
  if (!StrmPlikowy.is_open())  {
    cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << endl
	 << ":(  nie powiodla sie." << endl;
    return false;
  }

  PrzykladZapisuWspolrzednychDoStrumienia(StrmPlikowy, pro);

  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}



int main()
{
  Prostokat pro;
  pro.p1.tabw[0] = 100;
  pro.p1.tabw[1] = 100;
  pro.p2.tabw[0] = 100;
  pro.p2.tabw[1] = 400;
  pro.p3.tabw[0] = 700;
  pro.p3.tabw[1] = 400;
  pro.p4.tabw[0] = 700;
  pro.p4.tabw[1] = 100;
  cout << "Beginning" << endl;
  double temp1, temp2;
  temp1 = pro.blenght();
  temp2 = pro.slenght();
  cout << pro << endl;
  cout << "After" << endl;
  PrzykladZapisuWspolrzednychDoStrumienia(cout, pro);
  cout << endl;
  if(temp1 == pro.blen){
       std::cout << ":) Longer sides are equal." << std::endl;
       std::cout << "Before operation: " << temp1 << std::endl;
       std::cout << "After operation: " << pro.blen << std::endl;
   } 
   else{
       std::cout << ":( Longer sides are not equal." << std::endl;
       std::cout << "Before operation: " << temp1 << std::endl;
       std::cout << "After operation: " << pro.blen << std::endl; 
   }
   cout << endl;
   if(temp1 == pro.slen){
       std::cout << ":) Longer sides are equal." << std::endl;
       std::cout << "Before operation: " << temp1 << std::endl;
       std::cout << "After operation: " << pro.slen << std::endl;
   } 
   else{
       std::cout << ":( Longer sides are not equal." << std::endl;
       std::cout << "Before operation: " << temp1 << std::endl;
       std::cout << "After operation: " << pro.slen << std::endl; 
   }
   cout << endl;
  
  PzG::LaczeDoGNUPlota  Lacze;  // Ta zmienna jest potrzebna do wizualizacji
                                // rysunku prostokata

   //-------------------------------------------------------
   //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
   //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
   //  na dwa sposoby:
   //   1. Rysowane jako linia ciagl o grubosci 2 piksele
   //
  Lacze.DodajNazwePliku("prostokat.dat",PzG::RR_Ciagly,2);
   //
   //   2. Rysowane jako zbior punktow reprezentowanych przez kwadraty,
   //      których połowa długości boku wynosi 2.
   //
  Lacze.DodajNazwePliku("prostokat.dat",PzG::RR_Punktowy,2);
   //
   //  Ustawienie trybu rysowania 2D, tzn. rysowany zbiór punktów
   //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
   //  jako wspolrzedne punktow podajemy tylko x,y.
   //
  Lacze.ZmienTrybRys(PzG::TR_2D);

  
  // PrzykladZapisuWspolrzednychDoStrumienia(cout);
  // if (!PrzykladZapisuWspolrzednychDoPliku("prostokat.dat",50)) return 1;
  // Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
  // cout << "Naciśnij ENTER, aby kontynuowac" << endl;
  // cin.ignore(100000,'\n');

   //----------------------------------------------------------
   // Ponownie wypisuje wspolrzedne i rysuje prostokąt w innym miejscu.
   //
  
  if (!PrzykladZapisuWspolrzednychDoPliku("prostokat.dat", pro)) return 1;
  Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
  cout << "Naciśnij ENTER, aby kontynuowac" << endl;
  cin.ignore(100000,'\n');


}
