#include <iostream>
#include "BST.h"

int main() {

    BST<int> bst;
    bst.insert(1);
    bst.insert(2);
    bst.insert(3);
    bst.insert(4);
    bst.insert(6);
    bst.insert(7);
    bst.InTravel();
    return 0;
}
