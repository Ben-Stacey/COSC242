#include <stdio.h>
#include <stdlib.h>

#define OCEAN_MAX 41981

struct ocean_datum{
    int x;
    int y;
    double conc;
    
};

void print_ocean_datum(struct ocean_datum *o){
    printf("%d %d %.4f\n", o->x, o->x, o->conc);
}

int read_ocean_datum(struct ocean_datum *o){
    return 3 == scanf("%d %d %lg",  &o->x, &o->x, &o->conc);
}

/*void insertion_sort()*/

int main(void){
    struct ocean_datum ocean_data[OCEAN_MAX];
    int num_items;
    int i, j;
    double key;

    num_items = 0;
    while(num_items < OCEAN_MAX && read_ocean_datum(&ocean_data[num_items])){
        num_items++;
    }
    
    /* data[0]->conc */
    for(i = 1; i < OCEAN_MAX; i++){
        key = *(&ocean_data[i].conc);
        for(j = i - 1; j >= 0; j--){
            if(*(&ocean_data[j].conc) > key){ 
                *(&ocean_data[j + 1].conc) = *(&ocean_data[j].conc);
                *(&ocean_data[j].conc) = key;
            }
        }
    }

    for(i = 0; i < num_items; i++){
        print_ocean_datum(&ocean_data[i]);
    }

    return EXIT_SUCCESS;
}
