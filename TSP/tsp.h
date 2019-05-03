#ifndef TSP_TSP_H
#define TSP_TSP_H

#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    int size;
    int **graph;
public:
    Graph(int size);

    int **getGraph() const;

    int getSize() const;

};

void printGraph(Graph);

#endif //TSP_TSP_H
