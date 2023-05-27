#include "Zerowanie.h"
#include "Pomocnicze.hpp"

void Zerowanie::przeksztalc(Bitmapa& bmp)
{
    for(size_t i = 0; i < bmp.length(); i++)
    {
        for(size_t j = 0; j < bmp.width(); j++)
        {
            bmp(i, j)=false;
        }
    }
}
