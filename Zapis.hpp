#pragma once
#include <fstream>

class BST;

class Zapis{
    void dodajDoZapisu(BST*);
    void dodajDoZapisuTxt(int*, int);

    std::ofstream zapis;
    std::ifstream odczyt;
    std::string sciezka;
    int do_zapisu=0;
    
    public:
    void setSciezka(const std::string&);
    ~Zapis();
    Zapis(const std::string&);
    void zapiszDoPliku(BST*);
    void zapiszDoPlikuTxt(int*,int);
    void zapiszDoPlikuTxt(int);
    BST* wczytajZPliku(BST&, BST*,int,bool);
};
