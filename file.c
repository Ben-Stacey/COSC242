#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX 30000

void insertion_sort(int *a, int n){
    int key = 0, i, j;
    for(i = 0; i < n; i++){
        key = a[i];
        for(j = i - 1; j >= 0; j--){
            if(a[j] > key){
                a[j + 1] = a[j];
                a[j] = key;
            }
        }
    }
}

int main(void){
    FILE *infile;
    int my_array[ARRAY_MAX];
    int count = 0;
    int num_items;
    int i;
    
    if(NULL == (infile = fopen(argv[i], "r"))){\
        fprintf(stderr, "%s: can't find %s\n", argv[0], argv[1]);
        return EXIT_FAILURE;
    }

    num_items = 0;
    while(num_items < ARRAY_MAX && 1 == fscanf(infile, "%d", &my_array[num_items])){
        num_items++;
    }

    fclose(infile);

    for(i = 0; i < ARRAY_MAX; i++){
        insertion_sort(my_array, count);
    }

    return EXIT_SUCCESS;
}
