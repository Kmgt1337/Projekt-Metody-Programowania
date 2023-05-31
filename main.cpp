#include "BitmapaExt.hpp"
#include "Dylatacja.hpp"
#include "Erozja.hpp"
#include "ZlozeniePrzeksztalcen.hpp"

int main()
{
    // BitmapaExt aa(7, 7);
    // aa(3, 1) = aa(2, 2) = aa(3, 2) = aa(4, 2) = aa(1, 3) = aa(2, 3) = aa(3, 3) = aa(4, 3) = aa(5, 3) = aa(2, 4) = aa(3, 4) = aa(4, 4) = aa(3, 5) = true;
    // std::cout << aa << std::endl;

    // Dylatacja d;
    // d.przeksztalc(aa);
    // std::cout << aa << std::endl;

    Dylatacja dylatacja;
    Erozja erozja;

    BitmapaExt<bool> aa(5, 5);
    aa(1, 1) = aa(2, 1) = aa(3, 1) = aa(2, 2) = aa(1, 3) = aa(2, 3) = aa(3, 3) = true;

    erozja.przeksztalc(aa);
    dylatacja.przeksztalc(aa);

    ZlozeniePrzeksztalcen z;
    z.dodajPrzeksztalcenie(&dylatacja);
    z.dodajPrzeksztalcenie(&erozja);
    z.przeksztalc(aa);
    std::cout << aa << std::endl;

    std::vector<std::vector<bool>> vec = 
    {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 1, 1, 1, 0, 0},
        {0, 1, 1, 1, 1, 1, 0},
        {0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0}
    };

    BitmapaExt<bool> bitmapa_test{vec};
    z.przeksztalc(bitmapa_test);
    std::cout << bitmapa_test << std::endl;

    dylatacja.przeksztalc(bitmapa_test);
    erozja.przeksztalc(bitmapa_test);
    std::cout << bitmapa_test << std::endl;

    try
    {
        std::vector<std::vector<bool>> hehe =
        {
            {1, 1, 1, 0, 0},
            {0, 1, 1, 0, 1},
            {1, 1},
            {1, 0, 0, 1}
        };

        BitmapaExt<bool> aa{hehe};
    }
    catch(const myexceptions::bad_bitmap_size& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}