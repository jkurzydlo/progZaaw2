#include <bits/stdc++.h>
using namespace std;
 
class BST {
    int dane;
    BST *lewe, *prawe;
 
public:
    ~BST(){
        delete lewe;
        delete prawe;
    }
    BST() : dane(0),lewe(NULL),prawe(NULL){};
    BST(int wartosc){
        dane = wartosc;
        lewe = prawe = NULL;
    }
    BST* wstaw(BST* korzen, int wartosc){

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
 
};
 

