#include <string>
#include <fstream>
#include <iostream>
#include "BST.hpp"

class Zapis{
    void dodajDoZapisu(BST* wezel){
            if (wezel== NULL) return;

    //rozmiar++;           
    do_zapisu = wezel->getDane();
    //Konwersja inta do char* aby zapisać do pliku binarnego
    zapis.write((char*)(&do_zapisu),sizeof do_zapisu);
    dodajDoZapisu(wezel->getLewe());// Przejdz lewe poddrzewo
    dodajDoZapisu(wezel->getPrawe());// Przejdz prawe poddrzewo

}
  std::ofstream zapis;
  std::ifstream odczyt;
  std::string sciezka;
  int do_zapisu=0,rozmiar=0;

    public:
    ~Zapis(){
      zapis.close();
      odczyt.close();
    }
    Zapis(const std::string& sciezka):sciezka(sciezka){};
    

    void zapiszDoPliku(BST* korzen){
        zapis.open(sciezka,std::ios::binary);

        dodajDoZapisu(korzen);    
        zapis.close();

    }
    BST* wczytajZPliku(BST& drzewo, int rozmiar){
      BST temp_drzewo;
      BST* korzen = NULL;


      odczyt.open(sciezka,std::ios::binary);

      int* bin = new int[rozmiar];
      //wczytuje kolejne liczby, sizeof(bin[0]*rozmiar) oznacza rozmiar całej tablicy (dla 4 elementów -> 4*4(rozmiar inta) bajty)
      odczyt.read((char*)bin,sizeof(bin[0])*rozmiar);

      korzen=drzewo.wstaw(korzen,bin[0]);
      for(int i =1;i<rozmiar;i++)temp_drzewo.wstaw(korzen,bin[i]);

      return korzen;
      odczyt.close();
      //drzewo.wstaw()
    }
    
};