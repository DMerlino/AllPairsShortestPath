/* 
	Author: Daniel Kiel Merlino
	Date Due: 04/02/2018
	Course: CSCE 4110-001

	Program: All Pairs Shortest Path Term Project
*/


#include "graphs.h"

using namespace std;


/* buildGraph function takes in two integer parameters, rows and columns, then builds a 
   two dimensional graph as an integer vector. This function uses srand(), time(), and 
   rand() functions to generate randomized integers, or vertices, to build the graph. 
   The function returns the designed graph */
costMatrix buildGraph(int rows, int columns) {
	costMatrix graph(rows);
	srand(time(NULL));

	for (int i = 0; i < rows; i++) {
		graph[i] = vector<int>(columns);
		for (int j = 0; j < columns; j++) {
			if (i == j) {
				graph[i][j] = 0;
			} 
			else {
				graph[i][j] = rand() % 10;
			}
		}
	}
	return graph;
}

/* print function takes in a costMatrix parameter, matrix, and determines the size of the
   rows and columns. As the function cycles through each row and column, the ith and jth
   position is printed to the console */
void print(costMatrix matrix) {
	int rows = matrix.size();
	int columns = matrix[0].size();

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

/* writeOutputFile function takes in a string and costMatrix parameters, fileName and
   matrix respectively. An output file stream is opened and checked with error handling.
   A cout buffer is then redirected to the generated text file and prints the costMatrix
   graph to the file.  */
void writeOutputFile(string fileName, costMatrix matrix) {
	// Opens a file and redirects a cout buffer to the generated file  
	ofstream outFile(fileName, ofstream::out);
	streambuf * coutBuffer = cout.rdbuf();

	if (outFile.is_open()) {
		cout.rdbuf(outFile.rdbuf());
		print(matrix);
	}

	cout.rdbuf(coutBuffer);
	outFile.close();
}

/* readFile function takes in a single string parameter of fileName and opens an input
   file stream. Similar to the writeOutputFile function, a streambuf is used to instantiate
   a cin read buffer, which is then redirected to the text file that writeOutputFile
   created, then reads line by line building the graph into a vector */
costMatrix readFile(string fileName) {
	costMatrix matrix;
	string stream;

	ifstream inFile(fileName, ifstream::in);
	streambuf * cinBuffer = cin.rdbuf();

	int i = 0;
	int input;

	if (inFile.is_open()) {
		cin.rdbuf(inFile.rdbuf());

		while (getline(cin, stream)) {
			stringstream moreStream(stream);
			matrix.push_back(vector<int>(0));

			while(moreStream >> input) {
				matrix[i].push_back(input);
			}
		
		i++;
		}
	}

	cin.rdbuf(cinBuffer);
	inFile.close();
	return matrix;
}