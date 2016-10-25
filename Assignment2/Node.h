#ifndef NODE_H
#define NODE_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <vector>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <algorithm>

class Edge;

class Node{

public:
	vector<Edge> in_edges;
	vector<Edge> out_edges;
	double weight;
	string type;

	Node(vector<Edge> _in_edges, vector<Edge> _out_edges, double _weight, string _type);
	
};

#endif