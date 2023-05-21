#include "BitmapaExt.hpp"
#include "Pomocnicze.hpp"

BitmapaExt::BitmapaExt(unsigned int length, unsigned int width)
{
    if(_length < 2 || _width < 2)
    {
        throw myexceptions::bad_bitmap_size("Zly rozmiar bitmapy");
    }
    
    _length = length;
    _width = width;
    _bmp = f_create_2d_array<bool>(_length, _width);

    for(std::size_t i = 0; i < _length; i++)
    {
        for(std::size_t j = 0; j < _width; j++)
        {
            _bmp[i][j] = false;
        }
    }
}

BitmapaExt::~BitmapaExt()
{
    f_delete_2d_array(_bmp, _length);
}

std::ostream& operator<<(std::ostream& stream, const BitmapaExt& bmp)
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