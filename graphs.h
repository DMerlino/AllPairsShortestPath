/* 
	Author: Daniel Kiel Merlino
	Date Due: 04/02/2018
	Course: CSCE 4110-001

	Program: All Pairs Shortest Path Term Project
*/


#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <time.h>
#include <stdlib.h>

using namespace std;


typedef vector<vector <int> > costMatrix; 

costMatrix buildGraph(int, int);
void print(costMatrix);
void writeOutputFile(string, costMatrix);
costMatrix readFile(string);

