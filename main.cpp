#include "BST.hpp"
int main(){
    BST drzewo, *korzen = NULL;
    korzen = drzewo.wstaw(korzen,50);

    drzewo.wstaw(korzen,10);
    drzewo.wstaw(korzen,15);
    drzewo.wstaw(korzen,20);
    drzewo.usunElement(korzen,20);
    drzewo.inorder(korzen);
    drzewo.preorder(korzen);
}