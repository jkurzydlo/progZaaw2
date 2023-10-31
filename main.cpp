#include "BST.hpp"
#include "Zapis.hpp"
#include <iostream>

int main()
{

    BST drzewo, *korzen = NULL;
    Zapis z1("");

    while(1){
    char wybor;
    std::cout << "1.)Dodaj element do drzewa\n2.)Usun element\n3.)Wyswietl drzewo\n4.)Znajdz element\n5.)Zapisz do pliku binarnego\n5.)Zapisz do pliku tekstowego\n7.)Wczytaj z pliku binarnego\n8.)Wczytaj z pliku tekstowego\nOpcja: ";
    std::cin >> wybor;
    switch (wybor)
    {
    case '1':
    {
        std::string wartosc;
        std::cout << "Wpisz 's' zeby wyjsc\n";
        do
        {
            std::cout << "Podaj wartosc: ";
            std::cin >> wartosc;
            try
            {
                int liczba = std::stoi(wartosc);
                if(korzen == NULL) korzen = drzewo.wstaw(korzen,liczba);
                else drzewo.wstaw(korzen,liczba);
            }
            catch (std::exception)
            {
                if(wartosc != "s")std::cout << "Niepoprawne dane\n";
            }
        } while (wartosc != "s");

    }break;
    case '2':{
        std::string wartosc;
        std::cout << "Wpisz 's' zeby wyjsc\n";
        do
        {
            std::cout << "Podaj wartosc: ";
            std::cin >> wartosc;
            try
            {
                int liczba = std::stoi(wartosc);
                drzewo.usunElement(korzen,liczba);
            }
            catch (std::exception)
            {
                if(wartosc != "s")std::cout << "Niepoprawne dane\n";
            }
        } while (wartosc != "s");

    }break;
    case '3':{
        drzewo.inorder(korzen);
    }break;
    case '4':{
        std::string wartosc;
         std::cout << "Podaj wartosc: ";
            std::cin >> wartosc;
            try
            {
                int liczba = std::stoi(wartosc);
                std::cout<<drzewo.znajdzSciezke(korzen,liczba);
            }
            catch (std::exception)
            {
                std::cout << "Niepoprawne dane\n";
            }
    }case '5': {
        std::string sciezka;
        std::cout<<"Podaj nazwe plku ";
        std::cin>>sciezka;
        z1.setSciezka(sciezka);
        z1.zapiszDoPliku(korzen);
    }break;
    case '8':{
        std::string sciezka;
        std::cout<<"Podaj nazwe plku ";
        std::cin>>sciezka;

        z1.setSciezka(sciezka);
        z1.wczytajZPliku(drzewo,korzen,drzewo.getRozmiar(),true);
    }break;
    case '6':{
        std::string sciezka;
        std::cout<<"Podaj nazwe plku ";
        std::cin>>sciezka;
        std::string wartosc;
        do
        {
            
            std::cout << "Podaj wartosc: ";
            std::cin >> wartosc;
            try
            {
                //Jeśli nie uda się przekonwertować stringa na inta zostanie rzucony wyjątek i nie nastąpi zapis do pliku
                int liczba = std::stoi(wartosc);
                z1.zapiszDoPlikuTxt(liczba);
            }
            catch (std::exception)
            {
                //Jeśli użytkownik chce wyjść - nie pokazuj komunikatu
                if(wartosc != "s")std::cout << "Niepoprawne dane\n";
            }
        } while (wartosc != "s");
        

    }break;
    case '7':{
               std::string sciezka;
        std::cout<<"Podaj nazwe plku ";
        std::cin>>sciezka;

        z1.setSciezka(sciezka);
        z1.wczytajZPliku(drzewo,korzen,drzewo.getRozmiar(),false);
    }break;

    default:{ std::cout<<"Niepoprawna opcja\n"; exit(0);}
        break;
    }
    }

    Zapis z2("C:\\Users\\Jacek\\Desktop\\zapis1.txt");

    BST drzewo3, *korzen2 = NULL;
    korzen2 = drzewo.wstaw(korzen2, 11);
    drzewo3.wstaw(korzen2, 22);
    drzewo3.wstaw(korzen2, 33);
    drzewo3.wstaw(korzen2, 2);

    int tab[5]{1, 3, 6, 8, 7};

    // sizeof(tab)/sizeof(tab[0]) - ilość elementów w tablicy
    z2.zapiszDoPlikuTxt(tab, sizeof(tab) / sizeof(tab[0]));
    (z2.wczytajZPliku(drzewo3, korzen2, 5, true));
    drzewo3.inorder(korzen2);
    system("pause");
}