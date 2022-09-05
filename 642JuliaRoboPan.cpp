#include <iostream>
#include <vector>
#include <unordered_set>

int numCycles(const std::vector<int>& graph) {
	int cycles = 0;

	int nodes = graph.size();
	std::vector<bool> marked(nodes, false);

	for(int i = 0; i < nodes; ++i) {
		if(!marked[i]) {
			marked[i] = true;

			std::unordered_set<int> path;
			path.insert(i);

			int next = graph[i];
			while(!marked[next]) {
				marked[next] = true;
				path.insert(next);
				next = graph[next];
			}

			if(path.count(next)) {
				++cycles;
			}
		}
	}

	return cycles;
}

int main() {
	int nodes = 0;
	while(std::cin >> nodes) {
		std::vector<int> graph(nodes, 0);

		for(int i = 0; i < nodes; ++i) {
			std::cin >> graph[i];
			graph[i] -= 1;
		}

		std::cout << numCycles(graph) << "\n";
	}

	return 0;
}
