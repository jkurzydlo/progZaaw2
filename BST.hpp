#pragma once
using namespace std;
 
class BST {
    int dane;
    BST *lewe, *prawe;
public:
    ~BST();
    BST();
    BST(int);
    int getDane();
    BST* getLewe();
    BST* getPrawe();
    BST* wstaw(BST*,int);
    void inorder(BST*);
    void preorder(BST* wezel);
    void postorder(BST*);
    BST* usunElement(BST*, int);
    void usunCaleDrzewo(BST*);
    void wyswietlCaleDrzewo(BST*);
    bool znajdzSciezke(BST*,int);
};
 
