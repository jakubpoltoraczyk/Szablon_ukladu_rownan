#ifndef MATRIX_H
#define MATRIX_H

#include "vector.h" // dolaczenie deklaracji klasy Vector
#include <algorithm>

/* WAZNE - macierz interpretowana wierszowo - np. wektor(x1,y1,z1) sklada sie na pierwszy wiersz macierzy */
/* WAZNE - macierz pobierana jest w postaci transponowanej - np. kolumna (x1,x2,x3) sklada sie na pierwszy wiersz pliku */

template <template <typename T, int size> class Vector,typename T,int size>
class Matrix // klasa Matrix opisujaca matematyczna macierz
{
private:
    Vector<T,size> tab[size]; // tablica wektorow ktore skladaja sie na macierz
public:
    Matrix(); // konstruktor domyslny klasy Matrix
    explicit Matrix(const Vector<T,size> *wsk_tab); // jednoparametrowy konstruktor klasy Matrix przyjmujacy tablice obiektow klasy Vector
    const Vector<T,size> & operator [] (int n)const; // przeciazony operator [] (dostep do poszczegolnych wektorow - wersja const)
    Vector<T,size> & operator [] (int n); // przeciazony operator [] (dostep do poszczegolnych wektorow - wersja bez const)
    Vector<T,size> get_column(int n)const; // metoda zwracajaca dowolna kolumne macierzy
    void set_column(const Vector<T,size> & v, int number); // metoda ustawiajaca podana kolumne macierzy podanym wektorem
    void transposition(); // metoda wykonujaca transpozycje macierzy
    Matrix operator + (const Matrix & m)const; // metoda dodajaca do siebie dwie macierze
    Matrix operator - (const Matrix & m)const; // metoda odejmujaca od siebie dwie macierze
    Matrix operator * (const Matrix & m)const; // metoda mnozaca przez siebie dwie macierze
    Vector<T,size> operator * (const Vector<T,size> & v)const; // metoda mnozaca macierz przez wektor
    T det()const; // metoda liczaca wyznacznik macierzy
};

/* Funkcje bezposrednio zwiazane z klasa Matrix */
template <template <typename T, int size_> class Vector,typename T,int size>
std::ostream & operator << (std::ostream & o, const Matrix<Vector,T,size> & m); // przeciazenie operatora << dla macierzy
template <template <typename T, int size_> class Vector,typename T,int size>
std::istream & operator >> (std::istream & i, Matrix<Vector,T,size> & m); // przeciazenie operatora >> dla macierzy

#endif // MATRIX_H
