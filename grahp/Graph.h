#pragma once
#include<iostream>
#include<vector>
using namespace std;
class Graph
{
public:
	vector<pair<int, int>> edges;
	vector<vector<int>> matrix;
	vector<string> namelist;
	int EdgeCount;
	int VertexCount;
	int symbol_num;

public:
	Graph(int num_of_points);
	void add_edge(int from, int to, int value);
	void add_vertex();
	void PrintGraph();
	void dellete_edge(int from, int to);
	void dellete_vertex(int num);
};

