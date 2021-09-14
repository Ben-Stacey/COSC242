#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "rbt.h"
#include <string.h>

#define IS_BLACK(x) ((NULL == (x)) || (BLACK == (x)->colour))
#define IS_RED(x) ((NULL != (x)) && (RED == (x)->colour))

typedef enum { RED, BLACK } rbt_colour;

struct rbt_node{
    char *key;
    rbt_colour colour;
    rbt left;
    rbt right;
};

rbt rbt_new(){
    rbt b = NULL;
    return b;
}

rbt rbt_insert(rbt b, char *str){
    if(b == NULL){
        b = emalloc(sizeof(struct rbt_node));
        b->key = emalloc(sizeof(char) * (strlen(str) + 1));
        strcpy(b->key, str);
        b->right = NULL;
        b->left = NULL;
        return b;
    }else if(strcmp(b->key, str) == 0){
        b = rbt_fix(b);
        return b;
    }else if(strcmp(str, b->key) < 0){
        b->left = rbt_insert(b->left, str);
        b = rbt_fix(b);
        return b;
    }else{
        b->right = rbt_insert(b->right, str);
        b = rbt_fix(b);
        return b;
    }
}

int rbt_search(rbt b, char *str){
    if(b == NULL){
        return 0;
    }
    if(strcmp(str, b->key) == 0){
        return 1;
    }else if(strcmp(str,b->key) < 0){
        return rbt_search(b->left, str);
    }else{
        return rbt_search(b->right, str);
    }
}

void print_key(char *s){
    printf("%s", s);
}

void rbt_inorder(rbt b, void f(char *str)){
    if(b == NULL){
        return;
    }
    
    rbt_inorder(b->left, f);
    f(b->key);
    if(b->colour == RED){
        printf(": RED\n");
    }else{
        printf(": BLACK\n");
    }
    rbt_inorder(b->right, f);
}

void rbt_preorder(rbt b, void f(char *str)){
    if(b == NULL){
        return;
    }
    
    f(b->key);
    if(b->colour == RED){
        printf(": RED\n");
    }else{
        printf(": BLACK\n");
    }
    rbt_preorder(b->left, f);
    rbt_preorder(b->right, f);
}

rbt rbt_delete(rbt b, char *str){
    if(b == NULL){
        return b;
    }
    if(strcmp(b->key, str) > 0){
        b->left = rbt_delete(b->left, str);
        return b;
    }else if(strcmp(b->key, str) < 0){
        b->right = rbt_delete(b->right, str);
        return b;
    }else{
        if(b->left == NULL && b->left == NULL){
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
            rbt left_most;
            char word[256];
            rbt rightSubTree = b->right;
            while(rightSubTree->left != NULL){
                rightSubTree = rightSubTree->left;
            }
            left_most = rightSubTree;
            strcpy(word, left_most->key);
            left_most->key = erealloc(left_most->key, strlen(b->key));
            strcpy(left_most->key, b->key);
            strcpy(b->key, word);

            b->right = rbt_delete(b->right, str);
            return b;
        }
    }
}

rbt left_rotate(rbt r){
    rbt temp = r;
    r = r->right;
    temp->right = r->left;
    r->left = temp;
    return r;
}

rbt right_rotate(rbt r){
    rbt temp = r;
    r = r->left;
    temp->left = r->right;
    r->right = temp;
    return r;    
}


rbt rbt_fix(rbt b){
    if(IS_RED(b->left)){
        if(IS_RED(b->left->left)){
            if(IS_RED(b->right)){
                b->colour = RED;
                b->left->colour = BLACK;
                b->right->colour = BLACK;
            }else if(IS_BLACK(b->right)){
                b = right_rotate(b);
                b->colour = BLACK;
                b->right->colour = RED;
            }
        }else if(IS_RED(b->left->right)){
            if(IS_RED(b->right)){
                b->colour = RED;
                b->left->colour = BLACK;
                b->right->colour = BLACK;
            }else if(IS_BLACK(b->right)){
                b->left = left_rotate(b->left);
                b = right_rotate(b);
                b->colour = BLACK;
                b->right->colour = RED;
            }
        }
    }else if(IS_RED(b->right)){
        if(IS_RED(b->right->left)){
            if(IS_RED(b->left)){
                b->colour = RED;
                b->left->colour = BLACK;
                b->right->colour = BLACK;
            }else if(IS_BLACK(b->left)){
                b->right = right_rotate(b->right);
                b = left_rotate(b);
                b->colour = BLACK;
                b->right->colour = RED;
            }
        }else if(IS_RED(b->right->right)){
            if(IS_RED(b->left)){
                b->colour = RED;
                b->left->colour = BLACK;
                b->right->colour = BLACK;
            }else if(IS_BLACK(b->right)){
                b = right_rotate(b);
                b->colour = BLACK;
                b->right->right->colour = RED;
            }
        }
    }
    return b;
}

rbt rbt_free(rbt b){
    free(b->key);
    free(b);
    return b;
}
