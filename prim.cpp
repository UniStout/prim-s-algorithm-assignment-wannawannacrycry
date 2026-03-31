// prim.cpp
#include <iostream>
#include <vector>
#include <fstream>
#include <climits>
#include <string>
#include "prim.h"
using namespace std;


int minKey(vector<int> &key, vector<bool> &mstSet) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < mstSet.size(); v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// Print MST
void printMST(vector<int> &parent, vector<vector<int>> &graph) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < graph.size(); i++)
        cout << parent[i] << " - " << i << " \t"
             << graph[parent[i]][i] << " \n";
}

// Construct and print MST
void primMST(vector<vector<int>> &graph) {
    int V = graph.size();
  
    vector<int> parent(V);

    vector<int> key(V);

    vector<bool> mstSet(V);

    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
        
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        
        int u = minKey(key, mstSet);

        mstSet[u] = true;

        for (int v = 0; v < V; v++)
 
            if (graph[u][v] && mstSet[v] == false
                && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, graph);
}

vector<vector<int>> readGraphFromFile(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Could not open file " << filename << endl;
        exit(1);
    }

    int V, E;
    file >> V >> E;

    vector<vector<int>> graph(V, vector<int>(V, 0));

    for (int i = 0; i < E; i++) {
        int u, v, weight;
        file >> u >> v >> weight;
        graph[u][v] = weight;
        graph[v][u] = weight;
    }

    file.close();
    return graph;
}

int main() {
    vector<vector<int>> graph = readGraphFromFile("input.txt");

    primMST(graph);

    return 0;
}