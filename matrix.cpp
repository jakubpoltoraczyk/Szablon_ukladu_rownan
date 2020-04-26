#include "matrix.h" // dolaczenie klasy Matrix

/* Jest to plik z definicjami wszelkich funkcji zwiazanymi z klasa Matrix */

template <typename T,int size>
Matrix<T,size>::Matrix() // konstruktor domyslny dla Matrix
{
    for(int i=0;i<size;++i) // ustawienie poszczegolnych wierszy macierzy domyslnymi obiektami klasy Vector
        tab[i]=Vector<T,size>();
}

template <typename T,int size>
Matrix<T,size>::Matrix(const Vector<T,size> * wsk_tab) // konstruktor jednoparametrowy klasy Matrix przyjmujacy tablice obiektow klasy Vector
{
    for(int i=0;i<size;++i) // ustawienie poszczegolnych wierszy macierzy obiektami klasy Vector
        tab[i]=wsk_tab[i];
}

template <typename T,int size>
const Vector<T,size> & Matrix<T,size>::operator [] (int n)const // metoda dostepu do poszczegolnych wektorow macierzy - const
{
    if(n<size&&n>=0) // sprawdzenie poprawnosci indeksu
        return tab[n];
    std::cerr << "Blad: zly indeks macierzy\n";
    exit(1); // komunikat i wyjscie jesli zly indeks
}

template <typename T,int size>
Vector<T,size> & Matrix<T,size>::operator [] (int n) // metoda dostepu do poszczegolnych wektorow macierzy - bez const
{
    if(n<size&&n>=0) // sprawdzenie poprawnosci indeksu
        return tab[n];
    std::cerr << "Blad: zly indeks macierzy\n";
    exit(1); // komunikat i wyjscie jesli zly indeks
}

template <typename T,int size>
Vector<T,size> Matrix<T,size>::get_column(int n)const // pobranie kolumny macierzy
{
    T value[size]; // tablica pomocnicza sluzaca do przechowania poszczegolnych skladowych kolumny
    for(int i=0;i<size;++i) // zapisanie do tablicy poszczegolnych skladowych wybranej kolumny
        value[i]=tab[i][n];
    return Vector<T,size>(value); // zwrocenie odpowiednej kolumny w postaci wektora
}

template <typename T,int size>
void Matrix<T,size>::set_column(const Vector<T,size> & v, int number) // metoda ustawiajaca kolumne innym wektorem
{
    transposition(); // dokonanie transpozycji tak by kolumny macierzy staly sie jej wierszami
    tab[number]=v; // zamiana kolumny na inny wektor
    transposition(); // powrotna transpozycja macierzy
}

template <typename T,int size>
void Matrix<T,size>::transposition() // metoda wykonujaca transpozycje macierzy
{
    Matrix pom=*this; // macierz pomocnicza, ktora jest kopia prawdziwej
    for(int i=0;i<size;++i) // zamiana wierszy na kolumny
        tab[i]=pom.get_column(i);
}

template <typename T,int size>
Matrix<T,size> Matrix<T,size>::operator + (const Matrix & m)const // metoda dodajaca do siebie dwie macierze
{
    Matrix pom; // pomocnicza macierz
    for(int i=0;i<size;++i) // w petli dodawanie do siebie poszczegolnych elementow macierzy
        pom[i]=tab[i]+m[i];
    return pom; // zwrocenie nowej zsumowanej macierzy
}

template <typename T,int size>
Matrix<T,size> Matrix<T,size>::operator - (const Matrix & m)const // metoda odejmujaca od siebie dwie macierze
{
    Matrix pom; // pomocnicza macierz
    for(int i=0;i<size;++i) // w podwojnej petli odejmowanie od siebie poszczegolnych elementow macierzy
        pom[i]=tab[i]-m[i];
    return pom; // zwrocenie nowej zroznicowanej macierzy
}

template <typename T,int size>
Matrix<T,size> Matrix<T,size>::operator * (const Matrix & m)const // metoda mnozaca dwie macierze przez siebie
{
    Matrix pom; // pomocnicza macierz
    for(int i=0;i<size;++i) // poszczegolne elementy nowej macierzy jako iloczyn kolejnych wierszy i kolumn
        for(int j=0;j<size;++j)
            pom[i][j]=tab[i]*m.get_column(j);
    return pom; // zwrocenie nowego obiektu
}

template <typename T,int size>
Vector<T,size> Matrix<T,size>::operator * (const Vector<T,size> & v)const // metoda mnozaca macierz przez wektor
{
    T pom[size]; // tablica pomocnicza
    for(int i=0;i<size;++i) // mnozenie podanego wektora i odpowiednich wierszy macierzy
        pom[i]=tab[i]*v;
    return Vector<T,size>(pom); // zwrocenie powstalego na skutek mnozenia wektora (powstalego za pomoca konstruktora)
}

template <typename T,int size>
T Matrix<T,size>::det()const // metoda wyliczajaca wyznacznik macierzy
{
    using namespace std;
    using std::abs;
    T value,result;
    result=1.0; // zmienna do przechowywania tymczasowych wartosci oraz zmienna do przechowywania ostatecznego wyniku
    int counter=0; // licznik zamian wierszy
    Matrix pom=*this; // macierz pomocnicza bedaca kopia macierzy glownej
    for(int i=0;i<size-1;++i)
    {
        for(int j=i+1;j<size;++j)
        {
            if(abs(pom.tab[i][i])>epsilon) // jesli konkretna skladowa macierzy nie jest zerem
            { // nastapi doprowadzenie do wyzerowania pierwszego niezerowego elementu danego wiersza, poprzez odjecie dwoch wierszy od siebie
                value=pom.tab[j][i]/pom.tab[i][i]; // ustawienie value na iloraz dwoch konkretnych skladowych
                pom.tab[j]=pom.tab[j]-(pom.tab[i]*value); // odjecie od siebie dwoch wierszy, w tym jednego pomnozonego razy value
            }
            else // jesli konkretna skladowa jest zerem
            {
                for(int k=i+1;k<size;++k) // poszukiwanie w petli wiersza, ktorego odpowiednia skladowa nie jest zerem
                {
                    if(abs(pom.tab[k][i])>epsilon) // sprawdzenie warunku czy nie jest zerem
                    {
                        std::swap(pom.tab[i],pom.tab[k]); // zamiana miejscami dwoch wierszy (funkcja swap z biblioteki algorithm)
                        ++counter; // aktualizacja licznika
                        k=size; // przerwanie wykonania petli
                    }
                }
            }
        }
    }
    for(int i=0;i<size;++i) // przemnozenie przez siebie elementow lezacych na przekatnej macierzy
        result*=pom[i][i];
    if(counter%2!=0) // jesli licznik zamian jest nieparzysty
        result=-result; // zamiana znaku wyznacznika
    return result; // zwrocenie wartosci wyznacznika
}

template <typename T,int size>
std::ostream & operator << (std::ostream & o, const Matrix<T,size> & m) // przeciazenie operatora << dla obiektow klasy Matrix
{
    for(int i=0;i<size-1;++i) // wyswietlenie poszczegolnych wektorow macierzy za pomoca operatora << dla klasy Vector
        o << m[i] << std::endl;
    o << m[size-1]; // ostatni wiersz wyswietlany bez znaku nowej linii w celu zachowania niezmiennosci kodu zewnetrznego
    return o; // zwrocenie obiektu klasy ostream
}

template <typename T,int size>
std::istream & operator >> (std::istream & i, Matrix<T,size> & m) // przeciazenie operatora >> dla obiektow klasy Matrix
{
    for(int n=0;n<size;++n) // pobranie kolejnych obiektow Vector za pomoca przeciazonego dla nich operatora >> 
        i >> m[n];
    m.transposition();
    return i; // zwrocenie obiektu klasy istream
}