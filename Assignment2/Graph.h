#ifndef GRAPH_H
#define GRAPH_H

#include "Node.h"
#include "Edge.h"
#include <string>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
class Graph {
public:
	std::vector <Node*> nodes;
	std::vector <Edge*> edges;

	bool addNode(Node* node);
	bool addEdge(Edge* edge);

	void createGraph(std::vector<std::string>);

	void parseString(std::string tempStr);
};

#endif