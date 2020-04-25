#include "vector.cpp"
#include "matrix.cpp"
#include "system.cpp"
#include "zesp_fun.h"

template class Vector<double,5>;
template class Vector<Liczba,5>;
template class Matrix<Vector,double,5>;
template class Matrix<Vector,Liczba,5>;
template class System<Matrix,Vector,double,5>;
template class System<Matrix,Vector,Liczba,5>;
template std::ostream & operator << (std::ostream & o, const Vector<double,5> & v);
template std::ostream & operator << (std::ostream & o, const Vector<Liczba,5> & v);
template std::ostream & operator << (std::ostream & o, const Matrix<Vector,double,5>& v);
template std::ostream & operator << (std::ostream & o, const Matrix<Vector,Liczba,5>& v);
template std::ostream & operator << (std::ostream & o, const System<Matrix,Vector,double,5> & u);
template std::ostream & operator << (std::ostream & o, const System<Matrix,Vector,Liczba,5> & u);
template std::istream & operator >> (std::istream & i, Vector<double,5> & v);
template std::istream & operator >> (std::istream & i, Vector<Liczba,5> & v);
template std::istream & operator >> (std::istream & i, Matrix<Vector,double,5> & v);
template std::istream & operator >> (std::istream & i, Matrix<Vector,Liczba,5> & v);
template std::istream & operator >> (std::istream & i, System<Matrix,Vector,double,5> & u);
template std::istream & operator >> (std::istream & i, System<Matrix,Vector,Liczba,5> & u);