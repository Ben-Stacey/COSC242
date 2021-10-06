#ifndef GRAPH_H_
#define GRAPH_H_

#include <stdlib.h>
#include <stdio.h>
#include "mylib.h"
#include "graph.h"

enum state_e{
     UNVISITED,
     VISITED_SELF,
     VISITED_DESCENDANTS
};

struct node{
    int parent;
    int distance;
    enum state_e state;
    int finish;
};

struct graphrec{
    int size;
    struct node *nodes;
    int **links;
};

typedef struct graph *graph;

extern graph graph_new(int count);
extern void graph_dfs(graph g);
extern void print_list(graph g);
extern void print_distance(graph g);
extern void graph_add_edge(graph g, int node, int neighbour);
extern void graph_free(graph g);
extern void visit(graph g, int n);
extern int main(void);

#endif
