#include "BitmapaExt.hpp"
#include "Dylatacja.hpp"
#include "Erozja.hpp"
#include "Usrednianie.h"
#include "Zerowanie.h"
#include "Inwersja.h"
#include "ZlozeniePrzeksztalcen.hpp"

int main()
{
    // BitmapaExt aa(7, 7);
    // aa(3, 1) = aa(2, 2) = aa(3, 2) = aa(4, 2) = aa(1, 3) = aa(2, 3) = aa(3, 3) = aa(4, 3) = aa(5, 3) = aa(2, 4) = aa(3, 4) = aa(4, 4) = aa(3, 5) = true;
    // std::cout << aa << std::endl;

    // Dylatacja d;
    // d.przeksztalc(aa);
    // std::cout << aa << std::endl;

    // Dylatacja dylatacja;
    // Erozja erozja;

    // BitmapaExt<bool> aa(5, 5);
    // aa(1, 1) = aa(2, 1) = aa(3, 1) = aa(2, 2) = aa(1, 3) = aa(2, 3) = aa(3, 3) = true;

    // erozja.przeksztalc(aa);
    // dylatacja.przeksztalc(aa);

    // ZlozeniePrzeksztalcen z;
    // z.dodajPrzeksztalcenie(&dylatacja);
    // z.dodajPrzeksztalcenie(&erozja);
    // z.przeksztalc(aa);
    // std::cout << aa << std::endl;

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

    const BitmapaExt<bool> bitmapa_test{vec};
    BitmapaExt<bool> test_inwersja{bitmapa_test};
    BitmapaExt<bool> test_erozja{bitmapa_test};
    BitmapaExt<bool> test_dylatacja{bitmapa_test};
    BitmapaExt<bool> test_zerowanie{bitmapa_test};
    BitmapaExt<bool> test_usrednianie{bitmapa_test};
    BitmapaExt<bool> test_zlozenie{bitmapa_test};

    Inwersja i;
    Erozja e;
    Dylatacja d;
    Zerowanie z;
    Usrednianie u;

    std::cout << bitmapa_test << std::endl;

    i.przeksztalc(test_inwersja);
    std::cout << test_inwersja << std::endl;

    e.przeksztalc(test_erozja);
    std::cout << test_erozja << std::endl;

    d.przeksztalc(test_dylatacja);
    std::cout << test_dylatacja << std::endl;

    z.przeksztalc(test_zerowanie);
    std::cout << test_zerowanie << std::endl;

    u.przeksztalc(test_usrednianie);
    std::cout << test_usrednianie << std::endl;

    ZlozeniePrzeksztalcen zlozenie;
    zlozenie.dodajPrzeksztalcenie(&d);
    zlozenie.dodajPrzeksztalcenie(&i);
    zlozenie.dodajPrzeksztalcenie(&u);
    zlozenie.przeksztalc(test_zlozenie);
    std::cout << test_zlozenie << std::endl;

}