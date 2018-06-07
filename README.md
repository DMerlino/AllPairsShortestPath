# Dijkstra's and Floyd-Warshall's Algorithm Analysis

Author: Daniel Kiel Merlino
Course: CSCE 4110-001
Project: Algorithms Term Project
Due Date: 04/02/2018

## Included Files:
  - README.md
  - dijkstra.h
  - graphs.h
  - floyd.h
  - dijkstra.cpp
  - floyd.cpp
  - graphs.cpp
  - main.cpp
  - graphs.txt


### Program Procedures:
  - One bash file will run the program with a terminal command of, "bash run.sh" without quotes. 

    *** If there are issues accessing the bash file, run "chmod +x run.sh" to change the user session access rights to executable, then run "bash run.sh"

  - This command will run the program to randomly generate a directed, complete graph and apply both Dijkstra's and Floyd-Warshall's algorithms. 

  - To run with a specific input text file: "bash run.sh graphs.txt" without quotes will run the program with the given example text file, or replace graphs.txt with any input text file containing a directed, complete graph

  - Example input files must be formatted as:
    - Non-negative integers
    - Delimited by spaces, new line characters
    - Graphs must be directed and complete

### Example: 
	0 1 100 100 4
	20 0 5 40 3
	100 100 0 6 5
	100 40 6 0 12
	3 3 5 60 0


  - *Optional* If experiement metrics are desired, run "bash run.sh test" this will generate 40 test cases of randomly generated graphs and return graph size, Dijkstra's run time in miliseconds, and Floyd-Warshall's run time in miliseconds

### Note 
This program will create dijkstraGraph.txt and floydGraph.txt which contain the resulting cost matrix and solution to the all pairs shortest path problem, respectively. These files will be created for random graph generation or with example input text file options