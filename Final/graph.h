#pragma once
#include <unordered_map>
#include <vector>
#include <limits>
#include <algorithm>
#include <iostream>



#include "InputValidator.h"
class Graph
{
public:
	Graph();
	~Graph();

	void add_vertex(int a_routerId, const 	std::unordered_map<int, connectedRouter>& edges);


	std::vector<int> shortest_path(int start, int finish);

	std::unordered_map<int, const 	std::unordered_map<int, connectedRouter>> vertices;



};

