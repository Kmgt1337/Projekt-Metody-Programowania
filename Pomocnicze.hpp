#ifndef POMOCNICZE_HPP
#define POMOCNICZE_HPP

#include <new>
#include <iostream>

template<typename T>
T** f_create_2d_array(int rows, int cols)
{
    T** tab{nullptr};

    try
    {
        tab = new T*[rows]{};
    }
    catch(const std::bad_alloc& e)
    {
        std::cerr << "\nBlad przy tworzeniu tablicy" << std::endl;
        std::cin.ignore();
        exit(0);
    }

    for(int i = 0; i < rows; i++)
    {
        try
        {
            tab[i] = new T[cols]{};
        }
        catch(const std::bad_alloc& e)
        {
            std::cerr << "\nBlad przy tworzeniu tablicy" << std::endl;
            std::cin.ignore();
            exit(0);
        }
    }

    return tab; 
}

template<typename T>
void f_delete_2d_array(T** tab, int rows)
{
    for(int i = 0; i < rows; i++)
    {
        delete[] tab[i];
    }
    delete[] tab;
}

#endif