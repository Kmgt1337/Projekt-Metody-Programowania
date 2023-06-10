#include "ZlozeniePrzeksztalcen.hpp"
#include "BitmapaExt.hpp"
using namespace std;

/*
Funkcja dodaje przeksztalcenie do wektora przechowujacego kolejne przeksztalcenia
@param p wskaznik do obiektu klasy reprezentujacej przeksztalcenie
*/
void ZlozeniePrzeksztalcen::dodajPrzeksztalcenie(Przeksztalcenie* p)
{
    _przeksztalcenia.push_back(p);
}

/*
Funkcja wykonuje przeksztalcenia w kolejnosci podania do obiektu metoda dodajPrzeksztalcenie
@param bmp bitmapa dla ktorej nalezy wykonac przekszalcenia
*/
void ZlozeniePrzeksztalcen::przeksztalc(Bitmapa& bmp)
{
    for(std::size_t i = 0; i < _przeksztalcenia.size(); i++)
    {
        _przeksztalcenia.at(i)->przeksztalc(bmp);
    }
}
