#include "Usrednianie.h"
#include "Pomocnicze.hpp"

/*
Funkcja wykonuje przeksztalcenie bitmapy - u�rednianie
@param bmp bitmapa ktora ma zostac przeksztalcona
*/
void Usrednianie::przeksztalc(Bitmapa& bmp)
{
    bool** to_change = f_create_2d_array<bool>(bmp.length(), bmp.width());

    for(size_t i = 0; i < bmp.length() - 1; i++)
    {
        for(size_t j = 0; j < bmp.width(); j++)
        {
            int number_of_diff_color=0;
            if(i>0&&bmp(i-1, j)!=bmp(i, j)) number_of_diff_color++;
            if(i+1<bmp.width()&&bmp(i+1, j)!=bmp(i, j)) number_of_diff_color++;
            if(j>0&&bmp(i, j-1)!=bmp(i, j)) number_of_diff_color++;
            if(j+1<bmp.length()&&bmp(i, j+1)!=bmp(i, j)) number_of_diff_color++;
            if(number_of_diff_color>2) to_change[i][j]=true;
        }
    }

    // zamiana obliczonych elementow na przeciwny kolor
    for(size_t i = 0; i < bmp.length(); i++)
    {
        for(size_t j = 0; j < bmp.width(); j++)
        {
            if(to_change[i][j])
            {
                bmp(i, j) = !bmp(i, j);
            }
        }
    }
}
