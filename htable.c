#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "htable.h"
#include <stddef.h>
#include <string.h>
struct htablerec{
    char **keys;
    int *frequenies;
    int num_keys;
    int capacity;
};

htable htable_new(int capacity){
    htable result = emalloc(sizeof *result);
    result -> num_keys = 0;
    result -> capacity = capacity;
    result -> keys = emalloc(result ->  capacity * sizeof result -> keys[0]);
    result -> frequenies = emalloc(result ->  capacity * sizeof result -> frequenies[0]);
    return result;
}

void htable_free(htable h){
    free(h);
}

static unsigned int htable_word_to_int(char *word){
    unsigned int result = 0;

    while(*word != '\0'){
        result = (*word++ + 31 * result);
    }

    return result;
}

int htable_insert(htable h, char *string){
    int y, i = 0;

    y = htable_word_to_int(string);
    y = y / h -> capacity;

    while(i < h -> capacity){
        if(h -> keys[y] == NULL){
            h -> keys[y] = string;
            h -> frequenies[y] = 1;
            return 1;
        }else if(strcmp(h -> keys[y],string) == 0){
            h -> frequenies[y]++;
            return h -> frequenies[y];
        }else{
            i++;
            y++;
            y= y % h -> capacity;
        }
    }
    return 0;
}

void htable_print(htable h, FILE *stream){
    int i;

    for(i = 0; i < h -> num_keys; i++){
        fprintf(stream, "%s\n", h -> keys[i]);
    }
}
