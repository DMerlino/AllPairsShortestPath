Author: Daniel Kiel Merlino
Course: CSCE 4110-001
Project: Algorithms Term Project
Due Date: 04/02/2018

Program Procedures:
	- One bash file will run the program with a terminal command of, "bash run.sh" without quotes. 
	*** If there are issues accessing the bash file, run "chmod +x run.sh" to change the user session access rights to executable, then run "bash run.sh"
	
	- This command will run the program to randomly generate a directed, complete graph and apply both Dijkstra's and Floyd-Warshall's algorithms. 
	
	- To run with a specific input text file: "bash run.sh graphs.txt" without quotes will run the program with the given example text file, or replace graphs.txt with any input text file containing a directed, complete graph
	
	- *Optional* If experiement metrics are desired, run "bash run.sh test" this will generate 40 test cases of randomly generated graphs and return graph size, Dijkstra's run time in miliseconds, and Floyd-Warshall's run time in miliseconds