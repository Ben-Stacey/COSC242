#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX 6

void merge(int *arr, int *workspace, int n){
    int i, j, pillow ;

    j = n/2;
    i = 0;
    pillow = 0;

    while(i < n/2 && j < n){
        if(arr[i] < arr[j]){
            workspace[pillow] = arr[i];
            i++;
        }else{
            workspace[pillow] = arr[j];
            j++;
        }
        pillow++;
    }

    if(i == (n/2)){
        for(; j < n; j++){
            workspace[pillow] = arr[j];
            pillow++;
        }
    }else if(j == n){
        for(; i < n/2; i++){
            workspace[pillow] = arr[i];
            pillow++;
        }
    }
}

void mergeSort(int *arr, int *w, int n){
    int i;

    if(n < 2){
        return;
    }

    mergeSort(arr, w, n/2);
    mergeSort(arr + (n/2), w, n-(n/2) );
    merge(arr, w, n);

    for(i = 0; i < n; i++){
        arr[i] = w[i];
    }
}



void print_array(int *a, int n){
    if(n > 0){
        printf("%d\n", a[0]);
        print_array(a + 1, n - 1);
    }
}

int main(void){
    int arr[ARRAY_MAX];
    int arr2[ARRAY_MAX];
    int count = 0;

    while(count < ARRAY_MAX && 1 == scanf("%d", &arr[count])){
        count++;
    }
    
    mergeSort(arr, arr2, count);

    print_array(arr, count);

    return EXIT_SUCCESS;
}
