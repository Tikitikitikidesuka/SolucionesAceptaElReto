#include <stdio.h>
#include <stdint.h>

#define MAX_NODES 10000

#define TRUE  1
#define FALSE 0

static inline int_fast8_t fastIntInput(int_fast16_t* number) {
	register int_fast8_t input;

	*number = 0;
	input = getchar_unlocked();

	// Clear noise on buffer
	for(; (input < '0' || input > '9'); input = getchar_unlocked())
		if(input == EOF) return FALSE;

	// Get number
	for(; (input >= '0' && input <= '9'); input = getchar_unlocked())
		*number = *number * 10 + input - 48;

	return TRUE;
}

static inline void fastIntOutput(int_fast16_t x){
	int_fast8_t buffer[35];
	register int_fast8_t i = 0;
	do{
		buffer[i++] = (x % 10) + '0';
		x /= 10;
	} while(x);
	--i;
	while(i >= 0) putchar_unlocked(buffer[i--]);
	putchar_unlocked('\n');
}

static inline int_fast16_t numCycles(int_fast16_t* graph, int_fast16_t nodes) {
	int_fast16_t i;
	int_fast16_t cycles = 0;

	int_fast8_t marked[MAX_NODES];
	for(i = 0; i < nodes; ++i) {
		marked[i] = FALSE;
	}

	int_fast16_t path[MAX_NODES];
	int_fast8_t visitedCheck[MAX_NODES];
	for(i = 0; i < nodes; ++i) {
		visitedCheck[i] = FALSE;
	}

	for(i = 0; i < nodes; ++i) {
		if(!marked[i]) {
			marked[i] = TRUE;

			int_fast16_t visited = 0;
			path[visited++] = i;
			visitedCheck[i] = TRUE;

			int_fast16_t next = graph[i];
			while(!marked[next]) {
				marked[next] = TRUE;
				path[visited++] = next;
				visitedCheck[next] = TRUE;
				next = graph[next];
			}

			if(visitedCheck[next]) {
				++cycles;
			}

			int_fast16_t j;
			for(j = 0; j < visited; ++j) {
				visitedCheck[path[j]] = FALSE;
			}
		}
	}

	return cycles;
}

int main() {
	int_fast16_t nodes = 0;
	while(fastIntInput(&nodes)) {
		int_fast16_t graph[MAX_NODES];

		int_fast16_t i;
		for(i = 0; i < nodes; ++i) {
			fastIntInput(&graph[i]);
			graph[i] -= 1;
		}

		fastIntOutput(numCycles(graph, nodes));
	}

	return 0;
}
