/* 
	Author: Daniel Kiel Merlino
	Date Due: 04/02/2018
	Course: CSCE 4110-001

	Program: All Pairs Shortest Path Term Project
*/


#include "floyd.h"

using namespace std;


costMatrix floydWarshall(costMatrix matrix) {
	int i, j, k;

	//time = clock();
	for (k = 0; k < matrix.size(); k++) {
		for (i = 0; i < matrix.size(); i++) {
			for (j = 0; j < matrix.size(); j++) {
				if (matrix[i][j] > matrix[i][k] + matrix[k][j]) {
					matrix[i][j] = matrix[i][k] + matrix[k][j];
				}
			}
		}
	}

	//time = clock() - time;

	return matrix;
}
