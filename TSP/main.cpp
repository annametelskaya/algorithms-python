#include <time.h>
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
                int randomNumber = 1 + rand() % 100;
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

int getPathWeight(int **graph, vector<int> path) {
    int weight = 0;
    int prev_point = path[0];
    for (int i : path) {
        weight += graph[prev_point][i];
        prev_point = i;
    }
    weight += graph[path[0]][path[path.size() - 1]];
    return weight;
}

bool checkVertexInIndex(const vector<int> &path, int j) {
    for (int i:path)
        if (i == j)
            return false;
    return true;
}

void changePath(Graph graph, vector<int> path) {
    int iterationNumber = 0;
    for (int i = 0; i < path.size() - 1; i++) {
        for (int j = 0; j < path.size(); j++) {
            if (i != j) {
                iterationNumber++;
                vector<int> newpath = path;
                swap(newpath[i], newpath[j]);
                if (getPathWeight(graph.getGraph(), path) > getPathWeight(graph.getGraph(), newpath)) {
                    path = newpath;
                }
            }
        }
    }
    cout << "Number of iteration: " << iterationNumber << endl;
    cout << "Weight: " << getPathWeight(graph.getGraph(), path) << endl;
    cout << "Path: ";
    for (int i : path) {
        cout << i + 1 << " ";
    }
}

int main() {
    int size;
    cout << "Input number of vertex: ";
    cin >> size;
    Graph graph(size);
    printGraph(graph);
    vector<int> path;
    for (int i = 0; i < size; i++) {
        path.push_back(i);
    }
    cout << "Path: ";
    for (int i : path) {
        cout << i + 1 << " ";
    }
    cout << endl;
    cout << "Weight: " << getPathWeight(graph.getGraph(), path) << endl;
    changePath(graph, path);
}