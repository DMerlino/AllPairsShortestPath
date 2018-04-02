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


#include <time.h>
#include "graphs.h"
#include "graphs.cpp"
#include "dijkstra.h"
#include "dijkstra.cpp"
#include "floyd.h"
#include "floyd.cpp"


using namespace std;


int main(int argc, char * argv[]) {
	clock_t dijkstraTime;
	clock_t floydTime;
	srand(time(NULL));
	
	// Sets a random generated number of vertices between 50 and 1000 
	int graphSize = 50 + (rand() % (1000 - 50));
	cout << "Randomly Generated Graph Size: " << graphSize << endl;
  
  // Error handling
	if (argc > 2) {
		cout << endl;
		cout << "Too many arguments...please use ./a.out and then either random or a text file" 
		<< "name" << endl;
	}

	/* If the only command line argument is ./a.out, randomly generate the size of a graph
		 and run both Dijkstra's and Floyd-Warshall's algorithms 
	*/
	if (argc == 1) {
		costMatrix graph = buildGraph(graphSize, graphSize);
		
		// Begin clock time for Dijkstra's Algorithm
		dijkstraTime = clock();
		costMatrix dijkstraGraph = dijkstraAlgorithm(graph);
		// End clock time
		dijkstraTime = clock() - dijkstraTime;
		cout << "Dijkstra's Run Time: " << ((float)dijkstraTime/CLOCKS_PER_SEC) * 1000 << " ms"
		<< endl;
		
		// Begin clock time for Floyd-Warshall
		floydTime = clock();
		costMatrix floydWarshallGraph = floydWarshall(graph);
		// End clock time
		floydTime = clock() - floydTime;
		cout << "Floyd-Warshall Run Time: " << ((float)floydTime/CLOCKS_PER_SEC) * 1000 << " ms" 
		<< endl;
		
		writeOutputFile("dijkstraGraph.txt", dijkstraGraph);
		writeOutputFile("floydGraph.txt", floydWarshallGraph);
	}
	
	/* Else, the user entered ./a.out and a text file in the command line. Read in the text
	   file and run the given graph(s) through both Dijkstra's and Floyd-Warshall's Algorithms
	*/
	else {
		costMatrix moreGraph = readFile(argv[1]);
		
		// Begin clock time for Dijkstra's
		dijkstraTime = clock();
		costMatrix dijkstraGraph = dijkstraAlgorithm(moreGraph);
		// End clock time
		dijkstraTime = clock() - dijkstraTime;
		cout << "Dijkstra's Run Time: " << ((float)dijkstraTime/CLOCKS_PER_SEC) * 1000 << " ms"
		<< endl;
		
		// Begin clock time Floyd-Warshall
		floydTime = clock();
		costMatrix floydWarshallGraph = floydWarshall(moreGraph);
		// End clock time 
		floydTime = clock() - floydTime;
		cout << "Floyd-Warshall Run Time: " << ((float)floydTime/CLOCKS_PER_SEC) * 1000 << " ms"
		<< endl;
	
		writeOutputFile("dijkstraGraph.txt", dijkstraGraph);
		writeOutputFile("floydGraph.txt", floydWarshallGraph);
	}

	return 0;
}	