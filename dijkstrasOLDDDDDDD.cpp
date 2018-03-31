using namespace std;

cost_matrix dijkstras(cost_matrix);

//checks whether or not dijkstras is done
inline bool all_visited(bool* visited_nodes) {
	for (int i = 0; i < sizeof(visited_nodes) / sizeof(int); i++) {
		if (!visited_nodes[i]) {
			return false;
		}
	}

	return true;
}

//function that puts array into vector given the size of the array
inline vector<int> push_result(int* result_array, int size) {
	vector<int> resulting_vector;
	for (int i = 0; i < size; i++) {
		resulting_vector.push_back(result_array[i]);
	}

	return resulting_vector;
}

cost_matrix dijkstras(cost_matrix cm) {
	//initialize cost matrix to store all pairs shortest path values
	cost_matrix result = generate_graph(cm.size(), cm.size(), false);

	//initialize array to store visited nodes
	//if a node is visited, visited_node[node] = true
	bool visited_nodes[cm.size()];
	for (int i = 0; i < cm.size(); i++) {
		visited_nodes[i] = false;
	}

	//initialize an array that holds the distance from visited nodes
	//if array cannot be visited (no edge connects) then distance = -1
	int distance[cm.size()];
	int start, end;
	for (int i = 0; i < cm.size(); i++) {
		start = i; //start node

		// DIJKSTRA'S FOR PAIR STARTS HERE
		//initialize algorithm for this pair start, end
		visited_nodes[i] = true; //visit start node

		//loop until end node is visited
		while (!all_visited(visited_nodes)) {
			break;
		}

		//DIJKSTRA'S FOR PAIR ENDS HERE
		//done with dijkstra's for this pair, move on
		// push_result(result[start], distance);

		//reset variables for next pair
		for (int i = 0; i < cm.size(); i++) {
			visited_nodes[i] = false;
			distance[i] = 3;
		}
		result[start] = push_result(distance, cm.size());
	}


	//finally, return the cost matrix of all shortest paths
	return result;
}