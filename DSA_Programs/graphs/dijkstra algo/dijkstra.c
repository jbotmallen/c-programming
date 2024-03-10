#include "functions.c"

int main() {
	int **adj_matV2 = initializeMatrix();
	displayMatrix(adj_matV2);
	
	int* short_path = dijkstraAlgo(adj_matV2, 0);
	displayDijkstra(short_path, 0);
	
	return 0;
}
