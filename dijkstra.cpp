/* 
	Author: Daniel Kiel Merlino
	Date Due: 04/02/2018
	Course: CSCE 4110-001

	Program: All Pairs Shortest Path Term Project
*/


#include "dijkstra.h"

using namespace std;


/* completeNodes function takes in a boolean pointer to an array, nodesVisited, as a 
	 parameter and loops through returning true or false for nodes being visted or not 
	 visited yet, respectively 
*/
bool completeNodes(bool * nodesVisited, int size) {
	for (int i = 0; i < size; i++) {
		if (!nodesVisited[i]) {
			return false;
		}	
	}

	return true;
}


/* storeInVector function takes in an integer point to an array and an integer variable
	 size as parameters. A resulting vector is decalred and used to store the resulting nodes
	 from Dijkstra's algorithm, depending on the size of the array 
*/
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
	 function breaks out of the outer for loop and directly returns the values vector
*/
costMatrix dijkstraAlgorithm(costMatrix matrix) {
	costMatrix values = buildGraph(matrix.size(), matrix.size());


	// Array to store boolean values for visited nodes, which return as true
	bool nodesVisited[matrix.size()];

	int distanceArray[matrix.size()];
	int begin;
	int shortestDistance;
	int shortestDistanceIndex;


	// Loop through the nodesVisited array and initialize all elements to false
	for (int i = 0; i < matrix.size(); i++) {
		nodesVisited[i] = false; 
	}


	/* Loop through rows and columns of the cost adjacency matrix, update beginning and
	 ending variables, and update the ith element in nodesVisited to true
	*/
	for (int i = 0; i < matrix.size(); i++) {
		begin = i;
		
		// This loop initializes every element in the the nodesVisited and distanceArray arrays
		for (int x = 0; x < matrix.size(); x++) {
			nodesVisited[x] = false;
			distanceArray[x] = matrix[begin][x];
		}

		// Re-initialization of the nodesVisited and distanceArray to true and zero
		nodesVisited[begin] = true;
		distanceArray[begin] = 0;

		/* While every node in the graph has not been visited, initialize shortestDistance
		 and shortestDistanceIndex to -1 
		*/
		while(!completeNodes(nodesVisited, matrix.size())) {
			shortestDistance = -1;
			shortestDistanceIndex = -1;
			
			/* This for loop steps through the integer array, distanceArray, and runs through
				 conditional logic requiring shortestDistance to be greater than the ith element
				 of distanceArray -or- if shortestDistance is equal to -1; as well as ensuring 
				 the ith element of nodesVisited is equal to false   
			*/
			for (int i = 0; i < matrix.size(); i++) {
				if ((shortestDistance > distanceArray[i] || shortestDistance == -1) 
					&& nodesVisited[i] == false) {
					
					// Set the shortestDistance variable equal to the ith element of distanceArray
					shortestDistance = distanceArray[i];
					
					// Update the index value of the shortest distance found
					shortestDistanceIndex = i;
				}
			}

			/* Re-initialize the last visited node, that is the shortest distance index to true. 
				 This ensures the while loop above can operate and exit correctly, also the for 
				 loop below requires the index to be set true
			*/ 
			nodesVisited[shortestDistanceIndex] = true;
			
			/* This for loop helps determine the "n-1 paths from v" as per the given 
				 pseudo code for Dijkstra's Algorithm
			*/
			for (int i = 0; i < matrix.size(); i++) {
				/* If conditional logic updates the distances and checks that the ith element 
					 has not been visited and the ith element of distanceArray is greater than 
					 the distance array's shortestDistanceIndex plus the cost matrix 
					 shortestDistanceIndex element and ith element 
				*/
				if (!nodesVisited[i] && distanceArray[i] > distanceArray[shortestDistanceIndex]
				+ matrix[shortestDistanceIndex][i]) {
					
					// Update the ith element in distanceArray with the conditional logic above
					distanceArray[i] = distanceArray[shortestDistanceIndex] 
					+ matrix[shortestDistanceIndex][i];
				}
			}
		}
		
		/* Pushes the generated distanceArray and size of the cost matrix into the 
			 costMatrix type vector, values. This array has the shortest path values that 
			 will be used in the cost matrix row to build the shortest path cost matrix
    */
		values[begin] = storeInVector(distanceArray, matrix.size());
	}

	return values;
}


