#include "vector.cpp"
#include "matrix.cpp"
#include "system.cpp"
#include "zesp_fun.h"

template class Vector<double,5>;
template class Vector<Liczba,5>;
template class Matrix<double,5>;
template class Matrix<Liczba,5>;
template class System<double,5>;
template class System<Liczba,5>;
template std::ostream & operator << (std::ostream & o, const Vector<double,5> & v);
template std::ostream & operator << (std::ostream & o, const Vector<Liczba,5> & v);
template std::ostream & operator << (std::ostream & o, const Matrix<double,5>& v);
template std::ostream & operator << (std::ostream & o, const Matrix<Liczba,5>& v);
template std::ostream & operator << (std::ostream & o, const System<double,5> & u);
template std::ostream & operator << (std::ostream & o, const System<Liczba,5> & u);
template std::istream & operator >> (std::istream & i, Vector<double,5> & v);
template std::istream & operator >> (std::istream & i, Vector<Liczba,5> & v);
template std::istream & operator >> (std::istream & i, Matrix<double,5> & v);
template std::istream & operator >> (std::istream & i, Matrix<Liczba,5> & v);
template std::istream & operator >> (std::istream & i, System<double,5> & u);
template std::istream & operator >> (std::istream & i, System<Liczba,5> & u);