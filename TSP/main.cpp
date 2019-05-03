#include <time.h>
//#include <bits/stdc++.h>
#include "tsp.h"

Graph::Graph(int size) {
    srand(time(nullptr));
    this->size = size;
    graph = new int *[this->size];
    for (int i = 0; i < this->size; i++) {
        graph[i] = new int[this->size];
    }
    for (int i = 0; i < this->size; i++)
        for (int j = i; j < this->size; j++) {
            if (j == i)
                graph[i][j] = 0;
            else {
                int randomNumber = 1 + rand() % 14;
                graph[i][j] = randomNumber;
                graph[j][i] = randomNumber;
            }
        }
}

int Graph::getSize() const {
    return size;
}

int **Graph::getGraph() const {
    return graph;
}

void printGraph(Graph graph) {
    cout << endl;
    for (int i = 0; i < graph.getSize(); i++) {
        for (int j = 0; j < graph.getSize(); j++)
            cout << graph.getGraph()[i][j] << "\t";
        cout << endl;
    }
}

void getPathWeight(int **graph, vector<int> path) {
    int weight = 0;
    int prev_point = path[0];
    for (int i : path) {
        weight += graph[prev_point][i];
        prev_point = i;
    }
    weight += graph[path[0]][path[path.size()-1]];
    cout << "Weight: " << weight;
}

bool checkVertexInIndex(const vector<int> &path, int j) {
    for (int i:path)
        if (i == j)
            return false;
    return true;
}

vector<int> findPath(int **graph, int size) {
    vector<int> path;
    path.push_back(0);
    for (int i = 0; i < size; i++) {
        int previousPositionIndex = path[path.size() - 1];
        int nextPositionIndex = -1;
        int nextWeight = 999;
        for (int j = 0; j < size; j++) {
            int currentWeight = graph[previousPositionIndex][j];
            if (j != previousPositionIndex && currentWeight < nextWeight && checkVertexInIndex(path, j)) {
                nextPositionIndex = j;
                nextWeight = currentWeight;
            }
        }
        if (nextPositionIndex != -1)
            path.push_back(nextPositionIndex);
    }
    return path;
}

int main() {
    int size;
    cout << "Input number of vertex: ";
    cin >> size;
    Graph graph(size);
    printGraph(graph);
    vector<int> path = findPath(graph.getGraph(), graph.getSize());
    cout << "Path: ";
    for (int i : path) {
        cout << i + 1 << " ";
    }
    cout << endl;
    getPathWeight(graph.getGraph(), path);
}