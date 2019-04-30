#ifndef TSP_TSP_H
#define TSP_TSP_H

#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    vector<vector<int>> graph;
    int size;
public:
    Graph(int size);

    const vector<vector<int>> &getGraph() const;

    int getSize() const;

};

void printGraph();

#endif //TSP_TSP_H
