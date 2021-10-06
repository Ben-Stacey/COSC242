#include <stdlib.h>
#include <stdio.h>
#include "mylib.h"
#include "graph.h"
#include "queue.h"
#include <string.h>
#include <stddef.h>


graph graph_new(int count) {
    int i, j;
    graph result = emalloc(sizeof *result);
    result->size = count;
    result->nodes = emalloc(count*sizeof(struct node));
    result->links = emalloc(sizeof(result[0])*count);
    for (i=0; i < count; i++) {
        result->links[i] = emalloc(sizeof(result[0])*count);
        for (j = 0; j < count; j++) {
            result->links[i][j] = 0;
        }
    }
    return result;
}

void graph_bfs(graph g, int source){
    int i, node;
    queue q;

    for(i = 0; i < g->size; i++){
        g->nodes[i].parent = -1;
        g->nodes[i].distance = -1;
        g->nodes[i].state = UNVISITED;
    }

    q = queue_new();
    enqueue(q, source);
    g->nodes[source].state = VISITED_SELF;
    g->nodes[source].distance = 0;

    while(0 != queue_size(q)){
        node = dequeue(q);
        for(i = 0; i < g->size; i++){
            if(g->links[node][i] == 1 && g->nodes[i].state == UNVISITED){
                g->nodes[i].parent = -1;
                g->nodes[i].distance = -1;
                g->nodes[i].state = UNVISITED;
                enqueue(q, i);
            }
        }
        g->nodes[node].state = VISITED_DESCENDANTS;
    }
    graph_free(g);
}

void graph_add_edge(graph g, int node, int neighbour){
    if(node < g->size && neighbour < g->size){
        g->links[node][neighbour] = 1;
        g->links[neighbour][node] = 1;
    }
}

void print_list(graph g){
    int i, j, first;
    printf("Adjacenct list:\n");
    for(i = 0; i < g->size; i++){
        printf("%d |", i);
        first = 1;
        for(j = 0; j < g->size; j++){
            if(g->links[i][j] == 1 && first == 1){
                printf(" %d", j);
                first--;
            }else if(g->links[i][j] == 1){
                printf(", %d", j);
            }
        }
        printf("\n");
    }
    printf( "\n" );
}

void print_distance(graph g){
    int i;
    printf("Vertex Distance Pred");
    for(i = 0; i < g->size; i++){
        printf("%5d %5d %5d\n", i, g->nodes[i].distance, g->nodes[i].parent);
    }
}

void graph_free(graph g){
    int i;
    free(g->nodes);
    for(i = 0; i < g->size; i++){
        free(g->links[i]);
    }
    free(g->links);
    free(g);
}

int main(void){
    graph g;
    int count, node, neighbour;

    /*read in number of nodes and create graph*/
    printf("What size is the graph?");
    scanf("%d", &count);
    g = graph_new(count);
    
    /*Define relationship between nodes*/
    while(2 == scanf("%d %d", &count, &neighbour)){
        graph_add_edge(g, count, neighbour);
    }
    print_list(g);

    /*perform a bfs, output results and free memory*/
    graph_bfs(g, 1);
    print_distance(g);
    graph_free(g);
    
    return EXIT_SUCCESS;
} 
