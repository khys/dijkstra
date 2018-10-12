#include <stdio.h>

#define NNODE 6
#define INF 100 // infinity

int main(void) {
	int cost[NNODE][NNODE] = {
		{  0,   2, 5, 1,   INF, INF},
		{  2,   0, 3, 2,   INF, INF},
		{  5,   3, 0, 3,   1,     5},
		{  1,   2, 3, 0,   1,   INF},
		{INF, INF, 1, 1,   0,     2},
		{INF, INF, 5, INF, 2,     0}
	};
	int dist[NNODE];
	int prev[NNODE];
	int node[NNODE];
	int u, v, w, i, j, min;

	for (u = 0; u < NNODE; u++) {
		for (i = 0; i < NNODE; i++) {
			node[i] = 0;
		}
		node[u] = 1;
		for (v = 0; v < NNODE; v++) {
			dist[v] = cost[u][v];
			prev[v] = u;
		}
		for (i = 0; i < NNODE; i++) {
			min = INF;
			for (j = 0; j < NNODE; j++) {
				if (!node[j] && dist[j] < min) {
					w = j;
					min = dist[j];
				}
			}
			node[w] = 1;
			for (v = 0; v < NNODE; v++) {
				if (cost[w][v] != INF && !node[v]
					&& dist[v] > dist[w] + cost[w][v]) {
					dist[v] = dist[w] + cost[w][v];
					prev[v] = w;
				}
			}
		}
		printf("root node %c:\n\t", u + 'A');
		for (i = 0; i < NNODE; i++) {
			printf("[%c,%c,%d]", i + 'A', prev[i] + 'A', dist[i]);
		}
		printf("\n");
	}
}
