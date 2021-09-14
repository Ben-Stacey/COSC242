#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX 30000

/*Insertion sort method*/
void insertion_sort(int *a, int n){
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

/*main method*/
int main(void){
    int my_array[ARRAY_MAX];
    clock_t start, end;
    int i, count = 0;

    while(count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])){/*gets the user input*/
        count++;
    }

    start = clock();
    insertion_sort(my_array, count);/*calls the insertion sort method*/
    end = clock();
    
    for(i = 0; i < count; i++){
        printf("%d\n", my_array[i]);/*prints out the sorted array*/
    }

    fprintf(stderr, "%d %f\n", count, (end-start)/(double)CLOCKS_PER_SEC);
    
    return EXIT_SUCCESS;
}
