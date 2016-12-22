#include "Graph.h"



Graph::Graph()
{
}


Graph::~Graph()
{
}

//the first part is router id, the second part, the edges, are -> routerID/Cost
void Graph::add_vertex(int a_routerId, const std::unordered_map<int, connectedRouter>& edges)
{
	// Insert the connected nodes in unordered map
	vertices.insert(std::unordered_map<int, const 	std::unordered_map<int, connectedRouter>>::value_type(a_routerId, edges));
}

//vector of routerId's is returned -> shortest path between two points. this will generate an entire path
std::vector<int> Graph::shortest_path(int start, int finish)
{
	// Second arguments -> distances
	// Find the smallest distance in the already in closed list and push it in -> previous
	std::unordered_map<int, int> distances; // routerid, cost.
	std::unordered_map<int, int> previous; //router id, router id
	std::vector<int> nodes; // Open list
	std::vector<int> path; // Closed list

						   //comparison for cost between two router Ids
	auto comparator = [&](int left, int right) { return distances[left] > distances[right]; };

	//in all the vertices that we have, lets talk about each one.
	for (auto& vertex : vertices)
	{
		if (vertex.first == start)//routerId
		{
			distances[vertex.first] = 0;
		}
		else
		{
			distances[vertex.first] = std::numeric_limits<int>::max();
		}
		//push into the open list of nodes, the router id.
		nodes.push_back(vertex.first);
		//priority queue
		push_heap(begin(nodes), end(nodes), comparator);
	}

	while (!nodes.empty())//now we have an open list, and we're going start working with it till its empty.
	{
		//take one element from this. the smallest distance one.
		pop_heap(begin(nodes), end(nodes), comparator);

		//the smallest val
		int smallest = nodes.back();
		nodes.pop_back();

		std::cout << "Open list: ";
		for (std::vector<int>::const_iterator i = nodes.begin(); i != nodes.end(); ++i)
			std::cout << *i << ' ';
		std::cout << std::endl;

		if (smallest == finish)
		{
			while (previous.find(smallest) != end(previous))
			{
				path.push_back(smallest);
				smallest = previous[smallest];
				std::cout << "Closed list: ";
				for (std::vector<int>::const_iterator i = path.begin(); i != path.end(); ++i)
					std::cout << *i << ' ';
				std::cout << std::endl;
			}

			break;
		}

		if (distances[smallest] == std::numeric_limits<int>::max())
		{
			break;
		}
		//in the map inside of vertices, find the router id with the smallest, and loop up its map of neighbours
		for (auto& neighbor : vertices[smallest])
		{
			int alt = distances[smallest] + neighbor.second.linkCost;
			if (alt < distances[neighbor.first])//router id
			{
				distances[neighbor.first] = alt;
				previous[neighbor.first] = smallest;
				make_heap(begin(nodes), end(nodes), comparator);
			}
		}
	}

	return path;

}

