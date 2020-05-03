/* Deklaracja klasy Liczba oraz prototypy funkcji bezposrednio z nia zwiazanych */
#ifndef ZESP_FUN_H
#define ZESP_FUN_H
#include <iostream>
#include <cmath>

/* Deklaracja klasy dla liczb zespolonych */
class Liczba
{
private: // prywatne dwie skladowe: czesc rzeczywista i czesc urojona
    double real;
    double img;
public:
    Liczba(): real(0.0), img(0.0) {} // konstruktor domyslny ustawiajacy czesc rzeczywista i zespolona na zero
    Liczba(const double & r, const double & i): real(r), img(i) {} // konstruktor przyjumjacy czesc rzeczywista i zespolona
    double get_real()const{return real;} // metoda zwracajaca czesc rzeczywista
    double get_img()const{return img;} // metoda zwracajaca czesc urojona
    double get_modul()const{return real*real+img*img;} // metoda zwracajaca modul liczby zespolonej
    Liczba operator~()const; // metoda tworzaca sprzezenie liczby zespolonej
    Liczba operator-(){return Liczba(-real,-img);} // metoda zmieniajaca oba znaki liczby zespolonej
    Liczba operator+(const Liczba & l)const; // metoda dodawania dwoch liczb zespolonych
    const Liczba & operator+=(const Liczba & l){return *this=*this+l;} // metoda dodajaca dwie liczby zespolone (wersja skrocona)
    Liczba operator-(const Liczba & l)const; // metoda odejmowania dwoch liczb zespolonych
    const Liczba & operator-=(const Liczba & l){return *this=*this-l;} // to co wyzej (wersja skrocona)
    Liczba operator*(const Liczba & l)const; // metoda mnozenia dwoch liczb zespolonych
    const Liczba & operator*=(const Liczba & l){return *this=*this*l;} // to co wyzej (wersja skrocona)
    Liczba operator*(double n)const {return Liczba(real*n,img*n);} // metoda mnozaca liczbe zespolona przez liczbe typu double
    const Liczba & operator*=(double n){return *this=*this*n;} // to co wyzej (wersja skrocona)
    Liczba operator/(const Liczba & l)const; // metoda dzielenia dwoch liczb zespolonych
    const Liczba & operator/=(const Liczba & l){return *this=*this/l;} // to co wyzej (wersja skrocona)
    Liczba operator/(double n)const; // metoda dzielenia liczbe zespolonej przez liczby typu double
    const Liczba & operator/=(double n){return *this=*this/n;} // to co wyzej (wersja skrocona)
    bool operator==(const Liczba & l)const; // metoda porownania rownosci dwoch liczb zespolonych
    bool operator!=(const Liczba & l)const; // metoda sprawdzania roznosci dwoch liczb zespolonych
    bool operator>(double n)const; // metoda porownujaca (>) modul liczby zespolonej i liczbe typu double
    bool operator<(double n)const; // metoda porownujaca (<) modul liczby zespolonej i liczbe typu double
    const Liczba & operator=(double n); // metoda zamieniajaca liczbe typu double na liczbe zespolona
};

/* Funkcje bezposrednio zwiazane z klasa Liczba */
std::ostream & operator << (std::ostream & o, const Liczba & l); // przeciazany operator << dla liczby zespolonych klasy Liczba
std::istream & operator >> (std::istream & i, Liczba & l); // przeciazany operator << dla liczby zespolonej klasy Liczba, sprawdzajacy poprawnosc jej zapisu
inline Liczba abs(const Liczba & l){return Liczba(std::abs(l.get_real()),std::abs(l.get_img()));} // przeciazenie wartosci bezwzglednej dla liczby zespolonej
inline double sqrt(const Liczba & l){return sqrt(l.get_real());}
#endif // ZESP_FUN_H
