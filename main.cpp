#include "dijkstra.h"
#include "dijkstra.cpp"
#include "graphs.h"
#include "graphs.cpp"

using namespace std;

int main() {
	int rowSize = 10;
	int columnSize = 10;
	
	costMatrix graph = buildGraph(rowSize, columnSize);
	//print(graph);
	writeOutputFile("graphs.txt", graph);
	costMatrix moreGraph = readFile("graphs.txt");


	return 0;
}