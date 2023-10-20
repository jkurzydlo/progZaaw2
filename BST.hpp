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
   
};
 

