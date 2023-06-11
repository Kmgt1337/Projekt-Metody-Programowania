#include "BitmapaExt.hpp"
#include "Dylatacja.hpp"
#include "Erozja.hpp"
#include "Usrednianie.h"
#include "Zerowanie.h"
#include "Inwersja.h"
#include "ZlozeniePrzeksztalcen.hpp"

void menu()
{
    std::vector<std::vector<bool>> vec =
    {
        {0, 0},
        {0, 0}
    };

    BitmapaExt<bool> current_bitmap{vec};
    Inwersja i;
    Erozja e;
    Dylatacja d;
    Zerowanie z;
    Usrednianie u;
    ZlozeniePrzeksztalcen zloz;
    while(true)
    {
        system("cls");
        unsigned short answer;
        std::cout<<"Menu"<<std::endl;
        std::cout<<"----------------------------------"<<std::endl;
        std::cout<<"1.Wprowadz bitmape"<<std::endl;
        std::cout<<"2.Dylatacja"<<std::endl;
        std::cout<<"3.Erozja"<<std::endl;
        std::cout<<"4.Inwersja"<<std::endl;
        std::cout<<"5.Zerowanie"<<std::endl;
        std::cout<<"6.Usrednianie"<<std::endl;
        std::cout<<"7.Zlozenie przeksztalcen"<<std::endl;
        std::cout<<"8.Wyswietl bitmape"<<std::endl;
        std::cout<<"9.Wyjdz"<<std::endl;
        std::cout<<"Podaj opcje: ";
        std::cin>>answer;
        while(answer>9||answer==0)
        {
            std::cout<<"Niepoprawny indeks sprobuj ponownie: ";
            std::cin>>answer;
        }
        switch(answer)
        {
        case 1:
            {
                std::string file_name;
                std::cout<<"\nPodaj nazwe pliku przechowujacego bitmape: ";
                std::cin>>file_name;
                std::ifstream input_file;
                input_file.open(file_name.c_str());
                BitmapaExt<bool> new_bitmap(input_file);
                current_bitmap=new_bitmap;
                input_file.close();
                break;
            }
        case 2:
            {
                d.przeksztalc(current_bitmap);
                break;
            }
        case 3:
            {
                e.przeksztalc(current_bitmap);
                break;
            }
        case 4:
            {
                i.przeksztalc(current_bitmap);
                break;
            }
        case 5:
            {
                z.przeksztalc(current_bitmap);
                break;
            }
        case 6:
            {
                u.przeksztalc(current_bitmap);
                break;
            }
        case 7:
            {
                std::string input;
                std::cout << "\nPodaj ciag przeksztalcen do wykonania. Akceptowane znaki:\n"
                << "i - inwersja, e - erozja, d - dylatacja, z - zerowanie, u - usrednianie\n"
                << "przykladowy ciag: 'deuzi' wykona przeksztalcenia w nastepujacej kolejnosci:\n"
                << "dylatacja -> erozja -> usrednianie -> zerowanie -> inwersja. Inne znaki beda ignorowane\n"
                << "\nPodaj ciag przeksztalcen: ";
                std::cin >> input;

                for(const auto& token : input)
                {
                    tolower(token);
                    if(token == 'i') zloz.dodajPrzeksztalcenie(&i);
                    else if(token == 'e') zloz.dodajPrzeksztalcenie(&e);
                    else if(token == 'd') zloz.dodajPrzeksztalcenie(&d);
                    else if(token == 'z') zloz.dodajPrzeksztalcenie(&z);
                    else if(token == 'u') zloz.dodajPrzeksztalcenie(&u);
                }

                zloz.przeksztalc(current_bitmap);
                break;
            }
        case 8:
            {
                break;
            }
        case 9:
            {
                exit(0);
            }
        }
        std::cout<<"\nWynik: "<<std::endl<<current_bitmap<<std::endl;
        system("pause");
    }
}

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

    menu();
    return 0;
    
    // std::vector<std::vector<bool>> vec =
    // {
    //     {0, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 1, 0, 0, 0},
    //     {0, 0, 1, 1, 1, 0, 0},
    //     {0, 1, 1, 1, 1, 1, 0},
    //     {0, 0, 1, 1, 1, 0, 0},
    //     {0, 0, 0, 1, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 0, 0}
    // };

    // const BitmapaExt<bool> bitmapa_test{vec};
    // BitmapaExt<bool> test_inwersja{bitmapa_test};
    // BitmapaExt<bool> test_erozja{bitmapa_test};
    // BitmapaExt<bool> test_dylatacja{bitmapa_test};
    // BitmapaExt<bool> test_zerowanie{bitmapa_test};
    // BitmapaExt<bool> test_usrednianie{bitmapa_test};
    // BitmapaExt<bool> test_zlozenie{bitmapa_test};

    // std::cout << bitmapa_test << std::endl;

    // i.przeksztalc(test_inwersja);
    // std::cout << test_inwersja << std::endl;

    // e.przeksztalc(test_erozja);
    // std::cout << test_erozja << std::endl;

    // d.przeksztalc(test_dylatacja);
    // std::cout << test_dylatacja << std::endl;

    // z.przeksztalc(test_zerowanie);
    // std::cout << test_zerowanie << std::endl;

    // u.przeksztalc(test_usrednianie);
    // std::cout << test_usrednianie << std::endl;

    // BitmapaExt<bool> aa(5, 5);
    // aa(1, 1) = aa(2, 1) = aa(3, 1) = aa(2, 2) = aa(1, 3) = aa(2, 3) = aa(3, 3) = true;

    // Dylatacja d;
    // Usrednianie u;
    // ZlozeniePrzeksztalcen zlozenie;
    // u.przeksztalc(aa);
    // std::cout << aa << std::endl;

    // aa(1, 1) = aa(2, 1) = aa(3, 1) = aa(2, 2) = aa(1, 3) = aa(2, 3) = aa(3, 3) = true;
    // d.przeksztalc(aa);
    // std::cout << aa << std::endl;
}
