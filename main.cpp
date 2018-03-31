#include "graphs.h"
#include "graphs.cpp"
#include "dijkstra.h"
#include "dijkstra.cpp"

using namespace std;

int main() {
	int rowSize = 10;
	int columnSize = 10;
	
	costMatrix graph = buildGraph(rowSize, columnSize);
	//print(graph);
	//writeOutputFile("graphs.txt", graph);
	costMatrix moreGraph = readFile("unitTest.txt");

	costMatrix anotherGraph = dijkstraAlgorithm(moreGraph);
	print(anotherGraph);

	return 0;
}	