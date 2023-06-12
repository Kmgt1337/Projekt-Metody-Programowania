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
                ZlozeniePrzeksztalcen zloz;
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
                    if(token == 'i')      zloz.dodajPrzeksztalcenie(&i);
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
    try
    {
        menu();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
