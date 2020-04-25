#include "vector.h" // dolaczenie klasy Vector

/* Jest to plik z definicjami wszelkich funkcji zwiazanymi z klasa Vector */

template <typename T,int size>
Vector<T,size>::Vector() // konstruktor domyslny dla klasy Vector
{
    for(int i=0;i<size;++i) // ustawienie wszystkich skladowych wektora na zera
        data[i]=0.0;
}

template <typename T,int size>
Vector<T,size>::Vector(const T * tab) // konstruktor przyjmujacy tablice jako swoj argument
{
    for(int i=0;i<size;++i) // ustawienie odpowiednich skladowych wektora elementami tablicy
        data[i]=tab[i];
}

/*template <int size> 
double Vector<Liczba>::lenght() const
{

}*/

template <typename T,int size>
T Vector<T,size>::operator [] (int n)const // metoda dostepu do poszczeglonych skladowych wektora (przeciazony [] wersja const)
{
    if(n<size&&n>=0) // sprawdzenie poprawnosci indeksu
        return data[n]; // zwrocenie odpowiedniej skladowej
    std::cerr << "Blad: zly indeks wektora\n";
    exit(1); // w przypadku bledu komunikat i wyjscie
}

template <typename T,int size>
T & Vector<T,size>::operator [] (int n) // metoda dostepu do poszczeglonych skladowych wektora (przeciazony [] wersja nie const)
{
    if(n<size&&n>=0) // sprawdzenie poprawnosci indeksu
        return data[n]; // zwrocenie odpowiedniej skladowej
    std::cerr << "Blad: zly indeks wektora\n";
    exit(1); // w przypadku bledu komunikat i wyjscie
}

template <typename T,int size>
Vector<T,size> Vector<T,size>::operator + (const Vector & v) const // metoda dodajaca do siebie dwa wektory
{
    T tab[size]; // tablica pomocnicza do zapamietywania poszczegolnych sum skladowych dwoch wektorow
    for(int i=0;i<size;++i) // dodawanie do siebie poszczegolnych skladowych wektorow
        tab[i]=data[i]+v[i];
    return Vector(tab); // zwrocenie obiektu klasy Vector powstalego z sumy przekazanych dwoch wektorow (przy pomocy konstruktora)
}

template <typename T,int size>
Vector<T,size> Vector<T,size>::operator - (const Vector & v) const // metoda odejmujaca od siebie dwa wektory
{
    T tab[size]; // tablica pomocnicza do zapamietywania poszczegolnych sum skladowych dwoch wektorow
    for(int i=0;i<size;++i) // odejmowanie siebie poszczegolnych skladowych wektorow
        tab[i]=data[i]-v[i];
    return Vector(tab); // zwrocenie obiektu klasy Vector powstalego z sumy przekazanych dwoch wektorow (przy pomocy konstruktora)
}

template <typename T,int size>
T Vector<T,size>::operator * (const Vector & v)const // metoda mnozaca przez siebie dwa wektory (wynikiem jest liczba typu double)
{
    T sum; // zmienna do zapamietywania wyniku
    sum=0.0;
    for(int i=0;i<size;++i) // zgodnie ze wzorem sumowanie iloczynu tych samych skladowych wektorow
        sum+=data[i]*v[i];
    return sum; // zwrocenie wyniku
}

template <typename T,int size>
Vector<T,size> Vector<T,size>::operator * (T n)const // metoda mnozaca wektor przez liczbe typu double
{
    T tab[size]; // tablica pomocnicza sluzaca do zapamietania poszczegolnych nowych skladowych wektora
    for(int i=0;i<size;++i) // mnozenie poszczeglonych skladowych
        tab[i]=data[i]*n;
    return Vector(tab); // zwrocenie nowego przemnozonego obiektu typu Vector za pomoca konstruktora
}

template <typename T,int size>
std::ostream & operator << (std::ostream & o, const Vector<T,size> & v) // przeciazenie operatora << dla klasy Vector
{
    for(int i=0;i<size;++i) // wypisywanie w petli poszczegolnych skladowych wektora
        o << v[i] << " ";
    return o; // zwrocenie obiektu klasy ostream
}

template <typename T,int size>
std::istream & operator >> (std::istream & i, Vector<T,size> & v) // przeciazenie operatora >> dla klasy Vector
{
    for(int n=0;n<size;++n)
        i >> v[n];
    if(i.fail())
        v=Vector<T,size>();
    return i; // zwrocenie obiektu klasy istream
}