#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_MAX 10000
#define KEY_MAX 80

void *emalloc(size_t s){
    void *result = malloc(s);
    if(NULL == result){
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

/*Insertion sort method*/
void insertion_sort(char **a, int n){
    int i, j;
    char *key;

    for(i = 1; i < n; i++){
        key = a[i];
        for(j = i - 1; j >= 0; j--){
            if(strcmp(a[j], key) == 1){ 
                a[j + 1] = a[j];
                a[j] = key;
            }
        }
    }
}



/*main method*/
int main(void){
    char *wordlist[ARRAY_MAX];
    char randwords[KEY_MAX];
    int i, num_words;

    num_words = 0;
    while(num_words < ARRAY_MAX && 1 == scanf("%79s", randwords)){
        wordlist[num_words] = emalloc((strlen(randwords) + 1) * sizeof wordlist[0][0]);
        strcpy(wordlist[num_words], randwords);
        num_words++;
    }

    insertion_sort(wordlist, num_words);/*calls the insertion sort method*/
   
    for(i = 0; i < num_words; i++){
        printf("%79s\n", wordlist[i]);/*prints out the sorted array*/
    }

    for(i = 0; i < num_words; i++){
        free(wordlist[i]);
    }
    
    return EXIT_SUCCESS;
}
