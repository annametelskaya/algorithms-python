#include <time.h>
#include "tsp.h"

Graph::Graph(int size) {
    srand(time(nullptr));
    this->size = size;
    vector<int> row(size, 0);
    for (int i = 0; i < this->size; i++)
        graph.push_back(row);
    for (int i = 0; i < this->size; i++)
        for (int j = i; j < this->size; j++) {
            if (j == i)
                graph[i][j] = 0;
            else {
                int randomNumber = rand() % 15;
                graph[i][j] = randomNumber;
                graph[j][i] = randomNumber;
            }
        }
}

const vector<vector<int>> &Graph::getGraph() const {
    return graph;
}

int Graph::getSize() const {
    return size;
}

void printGraph(Graph graph) {
    for (const vector<int> &row: graph.getGraph()) {
        for (int number: row)
            cout << number << "\t";
        cout << endl;
    }
}

int main() {
    int size;
    cout << "Input number of vertex: ";
    cin >> size;
    Graph graph(size);
    printGraph(graph);
}