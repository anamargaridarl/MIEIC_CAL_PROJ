//
// Created by henri on 10-05-2019.
//
#include <iostream>
#include <fstream>
#include "GraphImporter.h"

using namespace std;

Graph<int> importGraph(string nodesFilePath, string edgesFilePath, string tagsFilePath) {
    Graph<int> graph;

    ifstream nodesFile(nodesFilePath);
    ifstream edgesFile(edgesFilePath);
    ifstream tagsFile(tagsFilePath);

    loadNodes(graph, nodesFile);
    loadEdges(graph, edgesFile);

    return graph;
}

void loadNodes(Graph<int> &graph, ifstream &nodesFile) {
    string line;
    getline(nodesFile, line);
    int numNodes = stoi(line);

    for (unsigned int i = 0; i < numNodes; i++) {
        int nodeID;
        float lat, lon;

        getline(nodesFile, line);
        sscanf(line.c_str(), "(%d, %f, %f)", &nodeID, &lat, &lon);
        graph.addVertex(nodeID);
    }
}

void loadEdges(Graph<int> &graph, ifstream &edgesFile) {
    string line;
    getline(edgesFile, line);
    int numEdges = stoi(line);

    for (unsigned int i = 0; i < numEdges; i++) {
        int originNodeID, destNodeID;

        getline(edgesFile, line);
        sscanf(line.c_str(), "(%d, %d)", &originNodeID, &destNodeID);
        graph.addEdge(originNodeID, destNodeID, 1);
    }
}