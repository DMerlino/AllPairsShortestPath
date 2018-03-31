#include "dijkstra.h"

using namespace std;

/* completeNodes function takes in a boolean pointer to an array, nodesVisited, as a 
	 parameter and loops through returning true or false for nodes being visted or not 
	 visited yet, respectively */
bool completeNodes(bool * nodesVisited) {
	for (int i = 0; i < sizeof(nodesVisited) / sizeof(int); i++) {
		if (!nodesVisited[i]) {
			return false;
		}	
	}

	return true;
}


/* storeInVector function takes in an integer point to an array and an integer variable
	 size as parameters. A resulting vector is decalred and used to store the resulting nodes
	 from Dijkstra's algorithm, depending on the size of the array */
vector<int> storeInVector(int * tempArray, int size) {
	vector<int> results;

	for (int i = 0; i < size; i++) {
		results.push_back(tempArray[i]);
	}
	
	return results;
}


/* dijkstraAlgorithm function is the logic for implementing Dijkstra's algorithm. The 
	 function takes in a costMatrix variable, matrix, as a parameter and calls the buildGraph
	 function with row/column size constraints. The costMatrix values, is the actual matrix
	 which will hold all pairs shortest path values. This function also calls completeNodes
	 and storeInVector functions. If the end node is visited in completeNodes, then the 
	 function breaks out of the outer for loop and directly returns the values vector.d */
costMatrix dijkstraAlgorithm(costMatrix matrix) {
	costMatrix values = buildGraph(matrix.size(), matrix.size());

	// Array to store boolean values for visited nodes, which return as true
	bool nodesVisited[matrix.size()];

	// Loop through the nodesVisited array and initialize all elements to false
	for (int i = 0; i < matrix.size(); i++) {
		nodesVisited[i] = false; 
	}

	int distanceArray[matrix.size()];
	int begin;
	int smallest;
	int shortestDistance;
	int shortestDistanceIndex;

	// Loop through rows and columns of the cost adjacency matrix, update beginning and
	// ending variables, and update the ith element in nodesVisited to true
	for (int i = 0; i < matrix.size(); i++) {
		begin = i;
		
		// This loop initializes every element in the the nodesVisited and distanceArray arrays
		for (int i = 0; i < matrix.size(); i++) {
			nodesVisited[i] = false;
			distanceArray[i] = matrix[begin][i];
		}

		nodesVisited[begin] = true;
		distanceArray[begin] = 0;

		while(!completeNodes(nodesVisited)) {
			shortestDistance = -1;
			shortestDistanceIndex = -1;
			
			for (int i = 0; i < sizeof(distanceArray) / sizeof(int); i++) {
				if ((shortestDistance > distanceArray[i] || shortestDistance == -1) 
					&& nodesVisited[i] == false) {
					
					shortestDistance = distanceArray[i];
					shortestDistanceIndex = i;
				}
			}

			nodesVisited[shortestDistanceIndex] = true;

			for (int i = 0; i < matrix.size(); i++) {
				if (!nodesVisited[i] && distanceArray[i] > distanceArray[shortestDistanceIndex]
				+ matrix[shortestDistanceIndex][i]) {
					
					distanceArray[i] = distanceArray[shortestDistanceIndex] 
					+ matrix[shortestDistanceIndex][i];
				}
			}
		}
		
		values[begin] = storeInVector(distanceArray, matrix.size());
	}

	return values;
}
