#ifndef PRIM_H
#define PRIM_H

#include <vector>
#include <string>
using namespace std;


int minKey(vector<int> &key, vector<bool> &mstSet);

void printMST(vector<int> &parent, vector<vector<int>> &graph);


void primMST(vector<vector<int>> &graph);

vector<vector<int>> readGraphFromFile(const string &filename);

#endif