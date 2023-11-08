#include "BST.hpp"
#include "Zapis.hpp"

#include <iostream>

void Zapis::dodajDoZapisu(BST* wezel){
    if (wezel== NULL) return;

    do_zapisu = wezel->getDane();
    zapis.write(reinterpret_cast<char*>(&do_zapisu),sizeof do_zapisu);
    dodajDoZapisu(wezel->getLewe());
    dodajDoZapisu(wezel->getPrawe());
}

void Zapis::dodajDoZapisuTxt(int* wezly, int rozmiar){
    for(int i =0;i< rozmiar;i++){
        zapis<<wezly[i]<<" ";
    }
}

Zapis::Zapis(const std::string& sciezka):sciezka(sciezka){};

void Zapis::setSciezka(const std::string& sciezka){
    this->sciezka = sciezka;
}

void Zapis::zapiszDoPliku(BST* korzen){
    zapis.open(sciezka,std::ios::binary);
    dodajDoZapisu(korzen);    
    zapis.close();
}

void Zapis::zapiszDoPlikuTxt(int* wezly, int rozmiar){
    zapis.open(sciezka);
    dodajDoZapisuTxt(wezly,rozmiar);
    zapis.close();
}

void Zapis::zapiszDoPlikuTxt(int wezel)
{
    zapis.open(sciezka,std::ios::app);
    zapis<<wezel;
}

BST* Zapis::wczytajZPliku(BST& drzewo, BST*korzen, int rozmiar, bool tekstowo){
    BST temp_drzewo;
    BST* temp_korzen = NULL;
    if(!tekstowo){
        odczyt.open(sciezka,std::ios::binary);

        int* bin = new int[rozmiar];
        odczyt.read(reinterpret_cast<char*>(bin),sizeof(bin[0])*rozmiar);

        korzen=drzewo.wstaw(temp_korzen,bin[0]);
        for(int i =1;i<rozmiar;i++)temp_drzewo.wstaw(temp_korzen,bin[i]);

    }else{
        odczyt.open(sciezka);

        string element;
        while (std::getline(odczyt,element,' '))
        {
            drzewo.wstaw(korzen, std::stoi(element));
        }
    }
    return korzen;
    odczyt.close();
}

Zapis::~Zapis(){
    zapis.close();
    odczyt.close();
}
