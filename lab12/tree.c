#include "bst.h"
#include "mylib.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
    bst b = bst_new();

    b = bst_insert(b, "d");
    b = bst_insert(b, "b");
    b = bst_insert(b, "a");
    b = bst_insert(b, "c");
    b = bst_insert(b, "f");
    b = bst_insert(b, "e");
    b = bst_insert(b, "g");

    printf("\nInorder\n");
    bst_inorder(b, print_key);
   
    printf("\nPreorder\n");
    bst_preorder(b, print_key);

    printf("\nDelete\n");
    b = bst_delete(b, "c");

    printf("\nPreorder\n");
    bst_preorder(b, print_key);

    printf("\nFree\n");
    b = bst_free(b);

    return EXIT_SUCCESS;
}
