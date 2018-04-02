#! /bin/bash

# Compile the all header and .cpp files with an output flag of program
g++ -o program main.cpp -std=c++11 

counter=1

# If there is only one argument whilst running the bash script, run ./program with randomly
# generated graphs 
if [[ $1 == "" ]]; then
	./program

# Else if the argument following ./program is "test", that will be run as a test flag and
# the program will be run 30 times for different test cases
elif [[ $1 == "test" ]]; then
	for run in {1..40}
	do
		./program
		echo $counter
		((counter++))
		# Sleep one second to give the srand() function in the main.cpp file to generate a new
		# seed for better random number generation
		sleep 1
	done

# Otherwise, run ./program and read in the next command line argument as an input text file
else
	./program $1
fi