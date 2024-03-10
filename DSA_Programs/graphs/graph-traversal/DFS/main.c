#include"header.h"

int main() {
	Graph g;
	
	initializeGraph(g);
	populateGraph(g);
	dfs(g, 0);
	
	return 0;
}
