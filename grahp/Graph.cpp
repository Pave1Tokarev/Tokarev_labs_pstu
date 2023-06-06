#include "Graph.h"
#include <SFML/Graphics.hpp>
#include<iostream>
using namespace std;
Graph::Graph(int num_of_points) {
    VertexCount = num_of_points;
    for (int i = 0;i < 25;i++) {
        vector<int> tmp;
        for (int j = 0;j < 25;j++) {
            tmp.push_back(0);
        }
        matrix.push_back(tmp);
    }
    symbol_num = 65;
    EdgeCount = 0;

}
void Graph::add_edge(int from, int to, int value) {
    EdgeCount++;
    pair<int, int> tmp = make_pair(from, to);
    edges.push_back(tmp);
    matrix[from][to] = value;
}
void Graph::add_vertex() {
    VertexCount++;
}
void Graph::dellete_edge(int from, int to) {
    matrix[from][to] = 0;
    EdgeCount--;
}
void Graph::dellete_vertex(int num) {
    VertexCount--;
}