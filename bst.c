#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "bst.h"
#include <string.h>

struct bst_node{
    char *key;
    bst left;
    bst right;
};


bst bst_new(){
    bst b = NULL;
    return b;
}

bst bst_insert(bst b, char *str){
    if(b == NULL){
        b = emalloc(sizeof(struct bst_node));
        b->key = emalloc(sizeof(char) * (strlen(str) + 1));
        strcpy(b->key, str);
        b->right = NULL;
        b->left = NULL;
        return b;
    }else if(strcmp(b->key, str) == 0){
        return b;
    }else if(strcmp(str, b->key) < 0){
        b->left = bst_insert(b->left, str);
        return b;
    }else{
        b->right = bst_insert(b->right, str);
        return b;
    }
}

int bst_search(bst b, char *str){
    if(b == NULL){
        return 0;
    }
    if(strcmp(str, b->key) == 0){
        return 1;
    }else if(strcmp(str,b->key) < 0){
        return bst_search(b->left, str);
    }else{
        return bst_search(b->right, str);
    }
}

void print_key(char *s){
    printf("%s\n", s);
}

void bst_inorder(bst b, void f(char *str)){
    if(b == NULL){
        return;
    }
    
    bst_inorder(b->left, f);
    f(b->key);
    bst_inorder(b->right, f);
}

void bst_preorder(bst b, void f(char *str)){
    if(b == NULL){
        return;
    }
    
    f(b->key);
    bst_preorder(b->left, f);
    bst_preorder(b->right, f);
}

bst bst_delete(bst b, char *str){
    if(b == NULL){
        return b;
    }
    if(strcmp(b->key, str) > 0){
        b->left = bst_delete(b->left, str);
        return b;
    }else if(strcmp(b->key, str) < 0){
        b->right = bst_delete(b->right, str);
        return b;
    }else{
        if(b->left == NULL && b->right == NULL){
            free(b->key);
            free(b);
            b = NULL;
            return b;
        }else if(b->left == NULL && b->right != NULL){
            free(b->key);
            free(b);
            b = b->right;
            return b;
        }else if(b->right == NULL && b->left != NULL){
            free(b->key);
            free(b);
            b = b->left;
            return b;
        }else{
            bst left_most;
            char word[256];
            bst rightSubTree = b->right;
            while(rightSubTree->left != NULL){
                rightSubTree = rightSubTree->left;
            }
            left_most = rightSubTree;
            strcpy(word, left_most->key);
            left_most->key = erealloc(left_most->key, strlen(b->key));
            strcpy(left_most->key, b->key);
            strcpy(b->key, word);

            b->right = bst_delete(b->right, str);
            return b;
        }
    }
}

bst bst_free(bst b){
    /**
    if(b == NULL){
        return NULL;
    }else if(b->key != NULL && b->left == NULL && b->right == NULL){
        free(b->key);
        b->key = NULL;
        free(b);
        return bst_free(b);
    }else{
        b->left = bst_free(b->left);
        b->right = bst_free(b->right);
        return bst_free(b);
    }
    */
    free(b->key);
    free(b);
    return b;
}
