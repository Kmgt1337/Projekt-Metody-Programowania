#ifndef BITMAPAEXT_HPP
#define BITMAPAEXT_HPP

#include "Bitmapa.hpp"
#include "MyExceptions.hpp"
#include "Pomocnicze.hpp"
#include <iostream>
#include <vector>

template <typename T>
class BitmapaExt : public Bitmapa
{
public:
    BitmapaExt(unsigned int length, unsigned int width);
    BitmapaExt(const std::vector<std::vector<T>>& bmp);

    ~BitmapaExt()
    {
        f_delete_2d_array<T>(_bmp, _length);
    }

    unsigned length() const override
    {
        return _length;
    }

    unsigned width() const override
    {
        return _width;
    }

    bool& operator() (unsigned x, unsigned y) override
    {
       if(x < 0 || x >= _length || y < 0 || y >= _width)
       {
            throw myexceptions::out_of_range("Przekroczno zakres bitmapy");
       }
       return _bmp[x][y];
    }

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

#endif