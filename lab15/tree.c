#include "rbt.h"
#include "mylib.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
    rbt b = rbt_new();

    b = rbt_insert(b, "h");
    b = rbt_insert(b, "l");
    b = rbt_insert(b, "i");
    b = rbt_insert(b, "f");
    b = rbt_insert(b, "j");
    b = rbt_insert(b, "g");
    b = rbt_insert(b, "k");
    b = rbt_insert(b, "d");
    b = rbt_insert(b, "a");
    b = rbt_insert(b, "e");
    b = rbt_insert(b, "b");
    b = rbt_insert(b, "c");

    printf("\nPreorder\n");
    rbt_preorder(b, print_key);
    
    b = rbt_free(b);

    return EXIT_SUCCESS;
}
