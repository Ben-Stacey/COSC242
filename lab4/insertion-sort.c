#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX 30000

/**
 * Insertion sort method
 * This is the insertion sort method 
 * called in the main
 * */
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

/**
 * This prints out the array once it has been sorted
 */
void print_array(int *a, int n){
    if(n > 0){
        printf("%d\n", a[0]);
        print_array(a + 1, n - 1);
    }
}

/**
 * main method
 * This method controls the ordering of the program
 */
int main(void){
    int my_array[ARRAY_MAX];
    int count = 0;

    //reads the data from the file into the program
    while(count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])){/*gets the user input*/
        count++;
    }

    insertion_sort(my_array, count);/*calls the insertion sort method*/

    print_array(my_array, count);
    
    return EXIT_SUCCESS;
}
