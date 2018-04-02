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

	for (int i = 0; i < rows; i++) {
		graph[i] = vector<int>(columns);
		for (int j = 0; j < columns; j++) {
			if (i == j) {
				graph[i][j] = 0;
			} 
			else {
				graph[i][j] = rand() % 1000 + 1;
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
		// Redirects the outFile readbuffer to std::cout
		cout.rdbuf(outFile.rdbuf());
		print(matrix);
	}

	// Re-initializes the cout buffer back to a cout buffer
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
		// Redirects the input readbuffer to std::cin
		cin.rdbuf(inFile.rdbuf());

		// While loop to read in line by line and run through the stream variable
		while (getline(cin, stream)) {
			stringstream moreStream(stream);
			matrix.push_back(vector<int>(0));

			// While there is input to read/stream
			while(moreStream >> input) {
				// Build the matrix
				matrix[i].push_back(input);
			}
		
		i++;
		}

		// Re-initialize the cin read buffer back to std::cin
		cin.rdbuf(cinBuffer);
		inFile.close();
	}
	
	// Error handling for a file name error
	else {
		cout << "Error, file not found..." << endl;
		exit(1);
	}

	return matrix;
}