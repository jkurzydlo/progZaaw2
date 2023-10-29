#include "BST.hpp"
#include "Zapis.hpp"

#include <iostream>

    void Zapis::dodajDoZapisu(BST* wezel){
            if (wezel== NULL) return;

    //rozmiar++;           
    do_zapisu = wezel->getDane();
    //Konwersja inta do char* aby zapisać do pliku binarnego
    zapis.write((char*)(&do_zapisu),sizeof do_zapisu);
    dodajDoZapisu(wezel->getLewe());// Przejdz lewe poddrzewo
    dodajDoZapisu(wezel->getPrawe());// Przejdz prawe poddrzewo

}
    void Zapis::dodajDoZapisuTxt(int* wezly, int rozmiar){
      //std::cout<<sizeof(wezly)/sizeof(wezly[0]);
      for(int i =0;i< rozmiar;i++){
        zapis<<wezly[i]<<" ";
      }
    }


    Zapis::Zapis(const std::string& sciezka):sciezka(sciezka){};
    

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

    BST* Zapis::wczytajZPliku(BST& drzewo, BST*korzen, int rozmiar, bool tekstowo){
      BST temp_drzewo;
      BST* temp_korzen = NULL;
      if(!tekstowo){
      odczyt.open(sciezka,std::ios::binary);

      int* bin = new int[rozmiar];
      //wczytuje kolejne liczby, sizeof(bin[0]*rozmiar) oznacza rozmiar całej tablicy (dla 4 elementów -> 4*4(rozmiar inta) bajty)
      odczyt.read((char*)bin,sizeof(bin[0])*rozmiar);

      korzen=drzewo.wstaw(temp_korzen,bin[0]);
      for(int i =1;i<rozmiar;i++)temp_drzewo.wstaw(temp_korzen,bin[i]);

      }else{
        odczyt.open(sciezka);

        string element;
        while (std::getline(odczyt,element,' '))
        {
          //zmiana string na int
          std::cout<<std::stoi(element);
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