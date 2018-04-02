/* 
	Author: Daniel Kiel Merlino
	Date Due: 04/02/2018
	Course: CSCE 4110-001

	Program: All Pairs Shortest Path Term Project
*/


#include "floyd.h"

using namespace std;


/* Beginning of Floyd-Warshall's Algorithm. This function reads in a given matrix and
   performs the algorithm with three nested for-loops. This is operates in O(n^3) run time
*/
costMatrix floydWarshall(costMatrix matrix) {
	int i, j, k;
	
	for (k = 0; k < matrix.size(); k++) {
		for (i = 0; i < matrix.size(); i++) {
			for (j = 0; j < matrix.size(); j++) {
				
				/* If the n x n matrix path from i to j is greater than the sum of paths i to k and
					 k to j, then set the sum of i to k and k to j equal to the matrix paths of i to j.
					 This provides the shortest path solution between verticies i and j
				*/
				if (matrix[i][j] > matrix[i][k] + matrix[k][j]) {
					matrix[i][j] = matrix[i][k] + matrix[k][j];
				}
			}
		}
	}

	return matrix;
}
