#ifndef BITMAPAEXT_HPP
#define BITMAPAEXT_HPP

#include "Bitmapa.hpp"
#include "MyExceptions.hpp"
#include "Pomocnicze.hpp"
#include <iostream>
#include <fstream>
#include <vector>

template <typename T>
class BitmapaExt : public Bitmapa
{
public:
    BitmapaExt(unsigned int length, unsigned int width);
    BitmapaExt(const std::vector<std::vector<T>>& bmp);
    BitmapaExt(const BitmapaExt<T>& other);
    BitmapaExt(std::ifstream &input_file);
    BitmapaExt<T>& operator=(const BitmapaExt<T>& other);
    ~BitmapaExt();

    /*
    Funkcja zwraca dlugosc bitmapy
    @return dlugosc bitmapy
    */
    unsigned length() const override
    {
        return _length;
    }

    /*
    Funkcja zwraca szerokosc bitmapy
    @return szerokosc bitmapy
    */
    unsigned width() const override
    {
        return _width;
    }

    /*
    Funkcja zwraca referencje do elementu bitmapy o danych koordynatach
    @param x lokalizacja elementu na dlugosci bitmapy
    @param y lokalizacja elementu na szerokosci bitmapy
    @return referencja do odpowiedniego elementu bitmapy
    */
    bool& operator() (unsigned x, unsigned y) override
    {
       if(x < 0 || x >= _length || y < 0 || y >= _width)
       {
            throw myexceptions::out_of_range("Przekroczno zakres bitmapy");
       }
       return _bmp[x][y];
    }

    /*
    Funkcja zwraca wartosc elementu bitmapy o danych koordynatach
    @param x lokalizacja elementu na dlugosci bitmapy
    @param y lokalizacja elementu na szerokosci bitmapy
    @return wartosc odpowiedniego elementu bitmapy
    */
    bool operator() (unsigned x, unsigned y) const override
    {
        if(x < 0 || x >= _length || y < 0 || y >= _width)
        {
            throw myexceptions::out_of_range("Przekroczno zakres bitmapy");
        }
        return _bmp[x][y];
    }

    template <typename T1>
    friend std::ostream& operator<<(std::ostream& stream, const BitmapaExt<T1>& bmp);

private:
    T** _bmp;
    unsigned int _length;
    unsigned int _width;
};

/*
Konstruktor tworzacy bitmape z dlugosci i szerokosci wype³niona wartoscia false
@param length dlugosc bitmapy
@param width szerokosc bitmapy
*/
template <typename T>
BitmapaExt<T>::BitmapaExt(unsigned int length, unsigned int width)
{
    if(_length < 2 || _width < 2)
    {
        throw myexceptions::bad_bitmap_size("Zly rozmiar bitmapy. Konstruktor BitmapaExt<T>(unsigned int, unsigned int)");
    }

    _length = length;
    _width = width;
    _bmp = f_create_2d_array<T>(_length, _width);

    for(size_t i = 0; i < _length; i++)
    {
        for(size_t j = 0; j < _width; j++)
        {
            _bmp[i][j] = false;
        }
    }
}

/*
Konstruktor tworzacy bitmape z wektora dwuwymiarowego
@param vec referencja do wektora na podstawie ktorego tworzymy bitmape
*/
template <typename T>
BitmapaExt<T>::BitmapaExt(const std::vector<std::vector<T>>& vec)
{
    if(vec.size() < 2 || vec.at(0).size() < 2)
    {
        throw myexceptions::bad_bitmap_size("Zly rozmiar bitmapy. Konstruktor BitmapaExt<T>(const std::vector<std::vector<T>&)");
    }

    _width = vec.at(0).size();
    _length = vec.size();

    for(const auto& e : vec)
    {
        if(e.size() != _width)
        {
            throw myexceptions::bad_bitmap_size("Zly rozmiar bitmapy. Konstruktor BitmapaExt<T>(const std::vector<std::vector<T>&)");
        }
    }

    _bmp = f_create_2d_array<bool>(_length, _width);

    for(size_t i = 0; i < _length; i++)
    {
        for(size_t j = 0; j < _width; j++)
        {
            _bmp[i][j] = vec.at(i).at(j);
        }
    }
}

/*
Konstruktor kopiujacy
@param other bitmapa do skopiowania
*/
template<typename T>
BitmapaExt<T>::BitmapaExt(const BitmapaExt<T>& other)
{
    _length = other._length;
    _width = other._width;
    _bmp = f_create_2d_array<T>(_length, _width);

    for(int i = 0; i < _length; i++)
    {
        for(int j = 0; j < _width; j++)
        {
            _bmp[i][j] = other._bmp[i][j];
        }
    }
}

/*
Prze³adowanie operatora przypisania zeby przypisywal
*/
template <typename T>
BitmapaExt<T>& BitmapaExt<T>::operator=(const BitmapaExt<T> &other)
{
    if(this == &other)
    {
        return *this;
    }

    _length = other._length;
    _width = other._width;
    _bmp = f_create_2d_array<T>(_length, _width);

    for(int i = 0; i < _length; i++)
    {
        for(int j = 0; j < _width; j++)
        {
            _bmp[i][j] = other._bmp[i][j];
        }
    }

    return *this;
}

/*
Funkcja wyswietla bitmape w konsoli
@param stream strumien do ktorego wypisac zawartosc bitmapy
@param bmp bitmapa ktora ma zostac wypisana
*/
template <typename T1>
std::ostream& operator<<(std::ostream& stream, const BitmapaExt<T1>& bmp)
{
    for(std::size_t i = 0; i < bmp.length(); i++)
    {
        for(std::size_t j = 0; j < bmp.width(); j++)
        {
            stream << bmp._bmp[i][j] << " ";
        }
        stream << std::endl;
    }

    return stream;
}

/*
Funkcja pobierajaca bitmape z pliku
@param input_file uchwyt do pliku z danymi bitmapy do za³adowania
*/
template <typename T>
BitmapaExt<T>::BitmapaExt(std::ifstream &input_file)
{
    input_file>>_width;
    input_file>>_length;
    _bmp = f_create_2d_array<bool>(_length, _width);

    if(_width<2||_length<2) throw myexceptions::bad_bitmap_size("Zly rozmiar bitmapy. Konstruktor BitmapaExt<T>(const std::vector<std::vector<T>&)");
    for(size_t i = 0; i < _length; i++)
    {
        for(size_t j = 0; j < _width; j++)
        {
            input_file>>_bmp[i][j];
        }
    }
}

template <typename T>
BitmapaExt<T>::~BitmapaExt()
{
    f_delete_2d_array<T>(_bmp, _length);
}

#endif
