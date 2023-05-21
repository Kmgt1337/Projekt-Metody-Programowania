#include "BitmapaExt.hpp"
#include "Dylatacja.hpp"

int main()
{
    BitmapaExt aa(7, 7);
    aa(3, 1) = aa(2, 2) = aa(3, 2) = aa(4, 2) = aa(1, 3) = aa(2, 3) = aa(3, 3) = aa(4, 3) = aa(5, 3) = aa(2, 4) = aa(3, 4) = aa(4, 4) = aa(3, 5) = true;

    std::cout << aa << std::endl;

    Dylatacja d;
    d.przeksztalc(aa);

    std::cout << aa << std::endl;
}