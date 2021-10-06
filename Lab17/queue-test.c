#include "mylib.h"
#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

int main(void){
    int i;
    queue q = queue_new();

    for(i = 0; i < 50; i++){
        enqueue(q, i);
    }
    
    queue_print(q);
    dequeue(q);
    enqueue(q, 7);
    queue_print(q);
    queue_free(q);
    
    return EXIT_SUCCESS;
}
