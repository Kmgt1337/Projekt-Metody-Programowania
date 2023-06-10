#include "Inwersja.h"
#include "Pomocnicze.hpp"


/*
Funkcja wykonuje przeksztalcenie bitmapy - inwersja
@param bmp bitmapa ktora ma zostac przeksztalcona
*/
void Inwersja::przeksztalc(Bitmapa& bmp)
{
    for(size_t i = 0; i < bmp.length(); i++)
    {
        for(size_t j = 0; j < bmp.width(); j++)
        {
            bmp(i, j)=!bmp(i, j);
        }
    }
}
