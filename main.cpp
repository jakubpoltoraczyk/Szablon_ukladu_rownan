#include "vector.h"
#include "system.h"
#include "matrix.h"
#include "zesp_fun.h"
#include <iostream>
#include <fstream>

void type_of_system(std::istream & i);

int main()
{
    std::ifstream plik;
    plik.open("plik");
    type_of_system(plik);
    plik.close();
    return 0;
}

void type_of_system(std::istream & i)
{
    switch(i.get())
    {
        case 'r':
        {
            System<double,5> rownanie;
            i >> rownanie;
            std::cout << rownanie << std::endl;
            break;
        }
        case 'c':
        {
            System<Liczba,5> rownanie;
            i >> rownanie;
            std::cout << rownanie << std::endl;
            break;
        }
        default:
            std::cerr << "Blad wyboru rodzaju rownania\n";
    }
}
