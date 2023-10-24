#include "Zapis.hpp"
int main(){
    BST drzewo, *korzen = NULL;
    korzen = drzewo.wstaw(korzen,50);

    drzewo.wstaw(korzen,10);
    drzewo.wstaw(korzen,15);
    drzewo.wstaw(korzen,20);
    drzewo.wstaw(korzen,12);
    drzewo.usunElement(korzen,20);
    drzewo.inorder(korzen);
    //drzewo.preorder(korzen);
    
    Zapis z1("C:\\Users\\Jacek\\Desktop\\zapis1.bin");
    z1.zapiszDoPliku(korzen);
    BST drzewo2;
    drzewo2.inorder(z1.wczytajZPliku(drzewo,4));
}