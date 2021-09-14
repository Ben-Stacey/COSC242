#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "flexarray.h"

struct flexarrayrec{
    int capacity;
    int itemcount;
    int *items;
};

flexarray flexarray_new(){
    flexarray result = emalloc(sizeof *result);
    result -> capacity = 2;
    result -> itemcount = 0;
    result -> items = emalloc(result -> capacity * sizeof result -> items[0]);
    return result;
}
void insertion_sort(int a[], int n){
    int key = 0, i, j;
    for(i = 1; i < n; i++){
        key = a[i];
        for(j = i - 1; j >= 0; j--){
            if(a[j] > key){
                a[j + 1] = a[j];
                a[j] = key;
            }
        }
    }
}

void flexarray_append(flexarray f, int num){
    if(f -> itemcount == f -> capacity){
        f -> capacity += f -> capacity;
        f -> items = erealloc(f -> items, f -> capacity * sizeof f -> items[0]);
    }
    f -> items[f -> itemcount] = num;
    f -> itemcount++;
}

void flexarray_print(flexarray f){
    int i;
    for(i = 0; i < f -> itemcount; i++){
        printf("%d\n", f -> items[i]);
    }
}

void flexarray_sort(flexarray f){
    insertion_sort(f -> items, f -> itemcount);
}

void flexarray_free(flexarray f){
    free(f);
}
