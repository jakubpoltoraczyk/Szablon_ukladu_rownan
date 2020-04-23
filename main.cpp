#include "used_templates.cpp"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    System<Matrix,Vector,Liczba,5> rownanie;
    std::ifstream plik;
    plik.open("plik");
    plik >> rownanie;
    std::cout << rownanie << std::endl;
    plik.close();
    return 0;
}