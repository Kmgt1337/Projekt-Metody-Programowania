#include "Erozja.hpp"
#include "Pomocnicze.hpp"
using namespace std;


/*
Funkcja wykonuje przeksztalcenie bitmapy - erozja
@param bmp bitmapa ktora ma zostac przeksztalcona
*/
void Erozja::przeksztalc(Bitmapa& bmp)
{
    // funkcja dziala tylko dla prostokatych bitmap
    // zlozonosc - O(n^2)
    // nie trzeba juz tutaj sprawdzac warunkow, poniewaz robi to konstruktor BitmapaExt

    // pomocnicza tablica tego samego rozmiaru co bitmapa - wskazuje na pola ktore bedziemy zamieniac z czarnego na bialy
    bool** to_change = f_create_2d_array<bool>(bmp.length(), bmp.width());

    // I przypadek brzegowy - lewy gorny punkt bitmapy
    if(!bmp(0, 0))
    {
        if(!bmp(1, 0) || !bmp(0, 1))
        {
            to_change[0][0] = true;
        }
    }

    //II przypadek brzegowy - lewy dolny punkt bitmapy
    if(!bmp(bmp.length() - 1, 0))
    {
        if(!bmp(bmp.length() - 2, 0) || !bmp(bmp.length() - 1, 1))
        {
            to_change[bmp.length() - 1][0] = true;
        }
    }

    /// III przypadek brzegowy - prawy gorny punkt bitmapy
    if(!bmp(0, bmp.width() - 1))
    {
        if(!bmp(0, bmp.width() - 2) || !bmp(1, bmp.width() - 1))
        {
            to_change[0][bmp.width() - 1] = true;
        }
    }

    // IV przypadek brzegowy - prawy dwolny punkt bitmapy
    if(!bmp(bmp.length() - 1, bmp.width() - 1))
    {
        if(!bmp(bmp.length() - 1, bmp.width() - 2) || !bmp(bmp.length() - 2, bmp.width() - 1))
        {
            to_change[bmp.length() - 1][bmp.width() - 1] = true;
        }
    }

    // V przypadek brzegowy - pierwsza kolumna
    for(size_t i = 1; i < bmp.length() - 1; i++)
    {
        if(!bmp(i - 1, 0) || !bmp(i + 1, 0) || !bmp(i, 1))
        {
            to_change[i][0] = true;
        }
    }

    // VI przypadek brzegowy - pierwszy wiersz
    for(size_t i = 1; i < bmp.width() - 1; i++)
    {
        if(!bmp(0, i - 1) || !bmp(0, i + 1) || !bmp(1, i))
        {
            to_change[0][i] = true;
        }
    }

    // VII przypadek brzegowy - ostatnia kolumna
    for(size_t i = 1; i < bmp.length() - 1; i++)
    {
        if(!bmp(i - 1, bmp.width() - 1) || !bmp(i + 1, bmp.width() - 1) || !bmp(i, bmp.width() - 2))
        {
            to_change[i][bmp.width() - 1] = true;
        }
    }

    // VIII przypadek brzegowy - ostatni wiersz
    for(size_t i = 1; i < bmp.width() - 1; i++)
    {
        if(!bmp(bmp.length() - 1, i - 1) || !bmp(bmp.length() - 1, i + 1) || !bmp(bmp.length() - 2, i))
        {
            to_change[bmp.length() - 1][i] = true;
        }
    }

    // obliczenia dla reszty bitmapy
    for(size_t i = 0; i < bmp.length(); i++)
    {
        for(size_t j = 0; j < bmp.width(); j++)
        {
            if(!bmp(i, j))
            {
                continue;
            }

            if(i != 0 && j != 0 && i != bmp.length() - 1 && j != bmp.width() - 1)
            {
                if(!bmp(i - 1, j) || !bmp(i + 1, j) || !bmp(i, j - 1) || !bmp(i, j + 1))
                {
                    to_change[i][j] = true;
                }
            }
        }
    }

    // zamiana obliczonych elementow na bialy
    for(size_t i = 0; i < bmp.length(); i++)
    {
        for(size_t j = 0; j < bmp.width(); j++)
        {
            if(to_change[i][j])
            {
                bmp(i, j) = false;
            }
        }
    }
}
