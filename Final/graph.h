#pragma once
#include <string>

class Node
{
public:
	Node(std::string name);
private:
	std::string name;
};

inline Node::Node(std::string name)
{
	name = name;
}

class Edge
{
public:
	Edge(Node* source, Node* destination, double cost);
private:
	Node* source;
	Node* destination;
	double cost;

};

Edge::Edge(Node* source, Node* destination, double cost)
{
	source = source;
	destination = destination;
	cost = cost;
}

class Graph
{
public:
	void AddEdge();
	void AddNode();

private:

};