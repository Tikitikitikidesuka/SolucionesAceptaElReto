#include <iostream>
#include <unordered_set>

#define MAX_NODES 10000

int numCycles(int* graph, int nodes) {
	int cycles = 0;

	bool marked[MAX_NODES];
	for(int i = 0; i < nodes; ++i) {
		marked[i] = false;
	}

	int path[MAX_NODES];
	bool visitedCheck[MAX_NODES];
	for(int i = 0; i < nodes; ++i) {
		visitedCheck[i] = false;
	}

	for(int i = 0; i < nodes; ++i) {
		if(!marked[i]) {
			marked[i] = true;

			int visited = 0;
			path[visited++] = i;
			visitedCheck[i] = true;

			int next = graph[i];
			while(!marked[next]) {
				marked[next] = true;
				path[visited++] = next;
				visitedCheck[next] = true;
				next = graph[next];
			}

			if(visitedCheck[next]) {
				++cycles;
			}

			for(int j = 0; j < visited; ++j) {
				visitedCheck[path[j]] = false;
			}
		}
	}

	return cycles;
}

int main() {
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int nodes = 0;
	while(std::cin >> nodes) {
		int graph[MAX_NODES];

		for(int i = 0; i < nodes; ++i) {
			std::cin >> graph[i];
			graph[i] -= 1;
		}

		std::cout << numCycles(graph, nodes) << "\n";
	}

	return 0;
}
