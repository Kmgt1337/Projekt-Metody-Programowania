#include "ZlozeniePrzeksztalcen.hpp"
#include "BitmapaExt.hpp"
using namespace std;

void ZlozeniePrzeksztalcen::dodajPrzeksztalcenie(Przeksztalcenie* p)
{
    _przeksztalcenia.push_back(p);
}

void ZlozeniePrzeksztalcen::przeksztalc(Bitmapa& bmp)
{    
    for(std::size_t i = 0; i < _przeksztalcenia.size(); i++)
    {
        _przeksztalcenia.at(i)->przeksztalc(bmp);
    }
}