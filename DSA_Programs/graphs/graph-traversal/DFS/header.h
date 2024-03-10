#ifndef HEADER_H
#define HEADER_H

#include<stdio.h>
#include<stdlib.h>
#define MAX_GRAPH 5

typedef struct node {
	int vertex;
	struct node* link;
} Node, *NodePtr;

typedef NodePtr Graph[MAX_GRAPH];

void initializeGraph(Graph G);
void insertSortedList(NodePtr* L, int elem);
void populateGraph(Graph G);
void dfs(Graph G, int source);
void dfsSearch(Graph G, int visited[], int source);

#endif
