#include "BitmapaExt.hpp"
#include "Dylatacja.hpp"
#include "Erozja.hpp"

int main()
{
    BitmapaExt aa(7, 7);
    aa(3, 1) = aa(2, 2) = aa(3, 2) = aa(4, 2) = aa(1, 3) = aa(2, 3) = aa(3, 3) = aa(4, 3) = aa(5, 3) = aa(2, 4) = aa(3, 4) = aa(4, 4) = aa(3, 5) = true;
    std::cout << aa << std::endl;

    Dylatacja d;
    d.przeksztalc(aa);
    std::cout << aa << std::endl;

    BitmapaExt aaa(7, 7);
    aaa(3, 1) = aaa(2, 2) = aaa(3, 2) = aaa(4, 2) = aaa(1, 3) = aaa(2, 3) = aaa(3, 3) = aaa(4, 3) = aaa(5, 3) = aaa(2, 4) = aaa(3, 4) = aaa(4, 4) = aaa(3, 5) = true;
    std::cout << aaa << std::endl;

    Erozja e;
    e.przeksztalc(aaa);
    std::cout << aaa << std::endl;
}