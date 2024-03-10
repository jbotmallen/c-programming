#include"header.h"

void initializeGraph(Graph G) {
	int i;
	
	for(i = 0; i < MAX_GRAPH; i++) {
		G[i] = NULL;
	}
}

void insertSortedList(NodePtr* L, int elem) {
	NodePtr* trav;
	
	for(trav = L; *trav != NULL && (*trav)->vertex < elem; trav = &(*trav)->link) {}
	
	if(*trav == NULL || (*trav)->vertex != elem) {
		NodePtr temp = (NodePtr) malloc(sizeof(Node));
		if(temp != NULL) {
			temp->vertex = elem;
			temp->link = *trav;
			*trav = temp;
		}
	}
}

void populateGraph(Graph G) {
	//INSERT FOR V0
	insertSortedList(&(G[0]), 1);
	insertSortedList(&(G[0]), 3);
	insertSortedList(&(G[0]), 4);
	
	//INSERT FOR V1
	insertSortedList(&(G[1]), 2);
	
	//INSERT FOR V2
	insertSortedList(&(G[2]), 0);
	insertSortedList(&(G[2]), 4);
	
	//INSERT FOR V3
	insertSortedList(&(G[3]), 2);
	insertSortedList(&(G[3]), 4);
}

void dfs(Graph G, int source) {
	int visited[MAX_GRAPH] = { 0 };
	
	visited[source] = 1;
	
	dfsSearch(G[source], visited, source);
}

void dfsSearch(NodePtr V, int visited[], int source) {
	if(visited[source] != 1) {
		visited[source] = 1;
		
		dfsSearch(V->link, visited, V->link->vertex);
	}
}

