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

