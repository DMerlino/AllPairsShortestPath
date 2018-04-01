/* 
	Author: Daniel Kiel Merlino
	Date Due: 04/02/2018
	Course: CSCE 4110-001

	Program: All Pairs Shortest Path Term Project

	Description: This project, written in C++, is meant to implement code to generate random
	directed and complete graphs for two different shortest path algorithms, Dijkstra's and 
	Floyd-Warshall. Each algorithm implementation has its own header file and implementation
	file, both are called through main.cpp. The graph functionality also has its own header
	file and implementation file. The term project requires a CPU run time analysis and 
	comparison between the two different algorithms to find out which one is faster and/or
	better. Finally, a typed report will be turned in with the analysis results, data, 
	charts, and graphs; also containing experiement procedures and a conclusion of results
 */


#include "graphs.h"
#include "graphs.cpp"
#include "dijkstra.h"
#include "dijkstra.cpp"
#include "floyd.h"
#include "floyd.cpp"
#include <time.h>

using namespace std;


//clock_t time;

int main(int argc, char * argv[]) {
	//srand(time(NULL));
	//int graphSize = rand() % 100;
	int rows = 10;
	int columns = 10;
	
  
	if (argc > 2) {
		cout << endl;
		cout << "Too many arguments...please use ./a.out and then either random or a text file" 
		<< "name" << endl;
	}

	if (argc == 1) {
		costMatrix graph = buildGraph(rows, columns);
		writeOutputFile("graph.txt", graph);
		costMatrix moreGraph = readFile("graph.txt");
		costMatrix dijkstraGraph = dijkstraAlgorithm(moreGraph);
		costMatrix floydWarshallGraph = floydWarshall(moreGraph);
		print(dijkstraGraph);
		cout << endl;
		print(floydWarshallGraph);
	}
	
	else {
		costMatrix moreGraph = readFile(argv[1]);
		costMatrix dijkstraGraph = dijkstraAlgorithm(moreGraph);
		costMatrix floydWarshallGraph = floydWarshall(moreGraph);
		print(dijkstraGraph);
		cout << endl;
		print(floydWarshallGraph);
	}

	return 0;
}	