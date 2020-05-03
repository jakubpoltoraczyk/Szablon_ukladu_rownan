#ifndef VECTOR_H
#define VECTOR_H

#include "zesp_fun.h"
#include <iostream>
#include <cmath>

const double epsilon=0.0000000001;

template <typename T, int size>
class Vector // Klasa Vector opisujaca matematyczny wektor
{
private:
    T data[size]; // tablica sluzaca do przechowywania skladowych wektora
public:
    Vector(); // konstruktor domyslny
    explicit Vector(const T * tab); // konstruktor przyjmujacy jako argument tablice wartosci typu double
    double lenght() const {return sqrt(*this**this);} // metoda zwracajaca dlugosc wektora
    T operator [] (int n) const; // przeciazony operator [] (dostep do skladowych wektora - wersja const)
    T & operator [] (int n); // przeciazony operator [] (dostep do skladowych wektora - wersja bez const)
    Vector operator + (const Vector & v) const; // metoda dodajaca do siebie dwa wektory
    Vector operator - (const Vector & v) const; // metoda odejmujaca od siebie dwa wektory
    T operator * (const Vector & v)const; // metoda mnozaca ze soba dwa wektory
    Vector operator * (const T & n)const; // metoda mnozaca wektor przez wartosc typu double
};

/* Funkcje bezposrednio zwiazane z klasa Vector */
template <typename T, int size>
std::ostream & operator << (std::ostream & o, const Vector<T,size> & v); // przeciazenie operatora << dla klasy Vector
template <typename T, int size>
std::istream & operator >> (std::istream & i, Vector<T,size> & v); // przeciazenie operatora >> dla klasy

#endif //VECTOR_H