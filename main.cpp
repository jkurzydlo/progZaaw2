#include "BST.hpp"
#include "Zapis.hpp"

int main(){
    BST drzewo, *korzen = NULL;
    korzen = drzewo.wstaw(korzen,50);

    drzewo.wstaw(korzen,10);
    drzewo.wstaw(korzen,15);
    drzewo.wstaw(korzen,20);
    drzewo.wstaw(korzen,12);
    drzewo.usunElement(korzen,20);
   // drzewo.inorder(korzen);
    //drzewo.preorder(korzen);
    
    Zapis z1("C:\\Users\\Jacek\\Desktop\\zapis1.bin");
    Zapis z2("C:\\Users\\Jacek\\Desktop\\zapis1.txt");
    
    z1.zapiszDoPliku(korzen);
    BST drzewo2;
    //drzewo2.inorder(z1.wczytajZPliku(drzewo,korzen,4,false));

    BST drzewo3, *korzen2=NULL;
    korzen2 = drzewo.wstaw(korzen2,11);
    drzewo3.wstaw(korzen2,22);
    drzewo3.wstaw(korzen2,33);
    drzewo3.wstaw(korzen2,2);

    int tab[5]{1,3,6,8,7};

    //sizeof(tab)/sizeof(tab[0]) - ilość elementów w tablicy
    z2.zapiszDoPlikuTxt(tab,sizeof(tab)/sizeof(tab[0]));
    (z2.wczytajZPliku(drzewo3,korzen2,5,true));
    drzewo3.inorder(korzen2);
}