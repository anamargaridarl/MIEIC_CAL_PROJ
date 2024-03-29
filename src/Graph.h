/*
 * Graph.h
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <queue>
#include <list>
#include <limits>
#include <cmath>
#include <tuple>
#include "MutablePriorityQueue.h"
#include "Vertex.h"

#define INF numeric_limits<double>::max()

using namespace std;

/*************************** Graph  **************************/

class Graph {
	vector<Vertex *> vertexSet;    // vertex set

    void dfsVisit(Vertex *v, vector<nodeInfo> & res) const;
    tuple<nodeInfo, vector<nodeInfo>> getShortestPath(nodeInfo point, vector<nodeInfo> destinations, bool aStar);
    bool checkValidPath(vector<nodeInfo> path, double &previousCost);
public:
	Vertex *findVertex(const nodeInfo &in) const;
	bool addVertex(const nodeInfo &in);
	bool addEdge(const nodeInfo &sourc, const nodeInfo &dest, double w);
	int getNumVertex() const;
	vector<Vertex *> getVertexSet() const;

	static double cartesianDistance (nodeInfo* point1, const nodeInfo* point2);
    static double squaredCartesianDistance (nodeInfo* point1, const nodeInfo* point2);

	void dijkstraShortestPath(const nodeInfo &s, const nodeInfo &e);
    void aStarShortestPath(const nodeInfo &s, const nodeInfo &e);

	vector<nodeInfo> getPath(const nodeInfo &origin, const nodeInfo &dest) const;
    double getCost(const nodeInfo &dest) const;
    void clear();

    vector<nodeInfo> dfs(Vertex* startVertex) const;
    void clearVisitedVertexes();

    vector<nodeInfo> nearestNeighbour(nodeInfo startPoint,  vector<tuple<nodeInfo, vector<nodeInfo>>> deliveries, bool twoOpts, bool aStar);
    double getPathCost(vector<nodeInfo> path);
    vector<nodeInfo> twoOpt(vector<nodeInfo> currentPath, vector<tuple<nodeInfo, vector<nodeInfo>>> deliveries);
    void twoOptSwap(int i, int j, vector<nodeInfo> &tmpPath, vector<nodeInfo> currentPath);
};

/**************** Single Source Shortest Path algorithms ************/



#endif /* GRAPH_H_ */
