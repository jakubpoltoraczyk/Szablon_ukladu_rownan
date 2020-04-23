#ifndef SYSTEM_H
#define SYSTEM_H

#include "matrix.h" // dolaczenie klasy Matrix

template <template <template <typename T, int size> class Vector,typename T,int size> class Matrix,template <typename T,int size> class Vector, typename T, int size>
class System // klasa System opisujaca matematyczne rownanie
{
private:
    Matrix<Vector,T,size> mat; // macierz
    Vector<T,size> vec; // wektor wyrazow wolnych
public:
    System(): mat(), vec() {} // konstruktor domyslny ustawiajacy macierz i wektor wyrazow wolnych na domyslne wartosci
    System(const Matrix<Vector,T,size> & m, const Vector<T,size> & v): mat(m), vec(v) {} // konstruktor przyjmujacy konkretna macierz i konkretny wektor
    const Matrix<Vector,T,size> & get_matrix() const {return mat;} // metoda zwracajaca macierz rownania
    const Vector<T,size> & get_vector() const {return vec;} // metoda zwracajaca wektor wyrazow wolnych rownania
    Vector<T,size> solve()const; // metoda rozwiazujaca rownanie za pomoca metody Cramera
    //Vector<T,size> vector_mistake() const {return get_matrix()*solve()-get_vector();} // metoda wyznaczajaca wektor bledu rownania
    //double value_of_mistake() const {return vector_mistake().lenght();} // metoda wyznaczajaca wartosc bledu rownania (dlugosc wektora bledu)
};

/* Funkcje bezposrednio zwiazane z klasa System */
template <template <template <typename T, int size> class Vector,typename T,int size> class Matrix,template <typename T,int size> class Vector, typename T, int size>
std::ostream & operator << (std::ostream & o, const System<Matrix,Vector,T,size> & u); // przeciazony operator << dla klasy System
template <template <template <typename T, int size> class Vector,typename T,int size> class Matrix,template <typename T,int size> class Vector, typename T, int size>
std::istream & operator >> (std::istream & i, System<Matrix,Vector,T,size> & u); // przeciazony operator >> dla klasy System

#endif // SYSTEM_H