#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX 30000

/*Selection sort method sorts the values given by the input*/
void selection_sort(int *a, int n){
    int i, temp = 0, j;
    for(i = 0; i < n; i++){
        for(j = i; j < n; j++){
            if(a[j] < a[i]){
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

/*main method*/
int main(void){
    int my_array[ARRAY_MAX];
    clock_t start, end;
    int i, count = 0;

    while(count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])){/*ask for the user input */
        count++;
    }

    start = clock();
    selection_sort(my_array, count);/*calls selection sort method to sort the values*/
    end = clock();
    
    for(i = 0; i < count; i++){
        printf("%d\n", my_array[i]);/*prints out the sorted values*/
    }

    fprintf(stderr, "%d %f\n", count, (end - start) / (double)CLOCKS_PER_SEC);
    
    return EXIT_SUCCESS;
}
