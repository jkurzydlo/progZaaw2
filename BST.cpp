#include <iostream>
#include "BST.hpp"

using namespace std;
 
    BST::BST() : dane(0),lewe(NULL),prawe(NULL){};
    BST::BST(int wartosc){
        dane = wartosc;
        lewe = prawe = NULL;
    }

    BST::~BST(){
        delete lewe;
        delete prawe;
    }

    int BST::getDane(){return dane;}
    BST* BST::getLewe(){return lewe;}
    BST* BST::getPrawe(){return prawe;}
    int BST::getRozmiar(){return rozmiar;}

    BST* BST::wstaw(BST* korzen, int wartosc){
        rozmiar++;
    //Jeśli drzewo jest puste dodaj korzeń    
    if (!korzen) 
    return new BST(wartosc);
    
    //Jesli wartosc jest wieksza wstaw do prawego poddrzewa
    if (wartosc > korzen->dane) 
        korzen->prawe = wstaw(korzen->prawe, wartosc);
    
    //Jesli wartosc jest mniejsza wstaw do lewgo poddrzewa
    else if (wartosc < korzen->dane) 
        korzen->lewe = wstaw(korzen->lewe, wartosc);
    
    return korzen;
    }
 
    // Wyświetlenie drzewa w porządku inorder
    void BST::inorder(BST* korzen){
            if (!korzen){std::cout<<"\n"; return;}
    
    inorder(korzen->lewe);
    cout << korzen->dane << " ";
    inorder(korzen->prawe);
    }

    void BST::preorder(BST* wezel){
            if (wezel == NULL)return;

    cout << wezel->dane << " ";
    preorder(wezel->lewe);// Przejdz lewe poddrzewo
    preorder(wezel->prawe);// Przejdz prawe poddrzewo
    }

    void BST::postorder(BST* wezel)
{
    if (wezel == NULL)return;
 
    postorder(wezel->lewe);
    postorder(wezel->lewe);
    cout << wezel->dane << " ";
}

    BST* BST::usunElement(BST* korzen, int wartosc){
        //Przypadek bazowy
         if (korzen == NULL)
        return korzen;
 


    //Rekurencyjne wywołanie usuwania funkcji
    if (korzen->dane > wartosc) {
        rozmiar--;
        korzen->lewe = usunElement(korzen->lewe, wartosc);
        return korzen;
    }
    else if (korzen->dane < wartosc) {
        rozmiar--;
        korzen->prawe = usunElement(korzen->prawe, wartosc);
        return korzen;
    }
 
    // Jeżeli jeden z synów jest pusty usun korzen i zwroc prawy badz lewy nastepnik
    if (korzen->lewe == NULL) {
        rozmiar--;
        BST* temp = korzen->prawe;
        delete korzen;
        return temp;
    }
    else if (korzen->prawe == NULL) {
        rozmiar--;
        BST* temp = korzen->lewe;
        delete korzen;
        return temp;
    }
 
    // Jezeli istnieja obaj synowie
    else {
 
        BST* nastepnikRodzic = korzen;
 
        // Znajdz nastepnik
        BST* nastepnik = korzen->prawe;
        while (nastepnik->lewe != NULL) {
            nastepnikRodzic = nastepnik;
            nastepnik = nastepnik->lewe;
        }
 
        //Usun nastepnik badz jesli go nie ma - przypisz prawego syna nastepnika do prawego syna rodzica
        if (nastepnikRodzic != korzen)
            nastepnikRodzic->lewe = nastepnik->prawe;
        else
            nastepnikRodzic->prawe = nastepnik->prawe;
 
        // Przypisz dane z nastepnika do korzenia
        korzen->dane = nastepnik->dane;
 
        delete nastepnik;
        rozmiar--;
        return korzen;
    }
    
    }

    // Usuwanie całego drzewa
    void BST::usunCaleDrzewo(BST* korzen) {
        rozmiar=0;
        if (korzen == NULL) {
            return;
        }
        usunCaleDrzewo(korzen->lewe);
        usunCaleDrzewo(korzen->prawe);
        delete korzen;
        korzen = NULL;
    }

    // Szukanie drogi do podanego elementu i wyświetlanie jej
    bool BST::znajdzSciezke(BST* korzen, int wartosc) {
        bool znaleziono = false; 
        if (korzen == NULL) {
            return false;
        }
        
        cout << korzen->dane << " ";
        
        if (korzen->dane == wartosc) znaleziono = true;
        
        if (wartosc < korzen->dane && znajdzSciezke(korzen->lewe, wartosc)) znaleziono = true;
        
        if (wartosc > korzen->dane && znajdzSciezke(korzen->prawe, wartosc)) znaleziono = true;
        
        return znaleziono;
    }

int BST::rozmiar=0;

