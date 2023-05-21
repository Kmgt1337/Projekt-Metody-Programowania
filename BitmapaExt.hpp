#ifndef BITMAPAEXT_HPP
#define BITMAPAEXT_HPP

#include "Bitmapa.hpp"
#include "MyExceptions.hpp"
#include <iostream>
#include <initializer_list>
#include <vector>

class BitmapaExt : public Bitmapa
{
public:
    BitmapaExt(unsigned int length, unsigned int width);
    BitmapaExt(const std::vector<std::vector<bool>>& bmp);

    ~BitmapaExt();

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

    friend std::ostream& operator<<(std::ostream& stream, const BitmapaExt& bmp);

private:
    bool** _bmp;
    unsigned int _length;
    unsigned int _width;
};

#endif