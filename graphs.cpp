#include "graphs.h"

using namespace std;

costMatrix buildGraph(int rows, int columns) {
	costMatrix graph(rows);


	for (int i = 0; i < rows; i++) {
		graph[i] = vector<int>(columns);
		for (int j = 0; j < columns; j++) {
			if (i == j) {
				graph[i][j] = 0;
			} 
			else {
				graph[i][j] = rand() % 100;
			}
		}
	}
	return graph;
}

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





























