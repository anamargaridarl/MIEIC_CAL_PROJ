#include "Graph.h"
#include <tuple>
#include <algorithm>

int Graph::getNumVertex() const {
    return vertexSet.size();
}

vector<Vertex*> Graph::getVertexSet() const {
    return vertexSet;
}

/*
 * Auxiliary function to find a vertex with a given content.
 */

Vertex* Graph::findVertex(const nodeInfo &in) const {
    for (auto v : vertexSet)
        if (v->info == in)
            return v;
    return nullptr;
}

/*
 *  Adds a vertex with a given content or info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */
bool Graph::addVertex(const nodeInfo &in) {
    if ( findVertex(in) != NULL)
        return false;
    vertexSet.push_back(new Vertex(in));
    return true;
}

/*
 * Clears the Graph's information
 */
void Graph::clear() {
    for(Vertex* vertex : vertexSet)
    {
        delete vertex;
    }

    vertexSet.clear();
}

/*
 * Adds an edge to a graph (this), given the contents of the source and
 * destination vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */
bool Graph::addEdge(const nodeInfo &sourc, const nodeInfo &dest, double w) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == NULL || v2 == NULL)
        return false;
    v1->addEdge(v2,w);
    return true;
}

/*
 * Performs a depth-first search (dfs) in a graph (this) starting in a given vertex.
 * Returns a vector with the contents of the vertices by dfs order.
 * Follows the algorithm described in theoretical classes.
 */
vector<nodeInfo> Graph::dfs(Vertex* startVertex) const {
    vector<nodeInfo> res;
    dfsVisit(startVertex, res);
    return res;
}

/*
 * Auxiliary function that visits a vertex (v) and its adjacent not yet visited, recursively.
 * Updates a parameter with the list of visited node contents.
 */
void Graph::dfsVisit(Vertex *v, vector<nodeInfo> & res) const {
    v->visited = true;
    res.push_back(v->info);
    for(auto edge : v->adj)
    {
        if(!edge.dest->visited) dfsVisit(edge.dest, res);
    }
}

void Graph::clearVisitedVertexes() {
    for(auto v : vertexSet)
    {
        v->visited = false;
    }
}

vector<nodeInfo> Graph::getPath(const nodeInfo &origin, const nodeInfo &dest) const{
    vector<nodeInfo> res;
    Vertex *d = findVertex(dest);
    while(d->path != NULL) {
        res.push_back(d->getInfo());
        d = d->path;
    }
    res.push_back(origin);
    reverse(res.begin(),res.end());
    return res;
}

double Graph::getCost(const nodeInfo &dest) const{
    Vertex *destV = findVertex(dest);
    return destV->getDist();
}

double Graph::cartesianDistance (nodeInfo* point1, const nodeInfo* point2) {
    return (sqrt(pow(point1->lon-point2->lon,2)+pow(point1->lat-point2->lat,2)));
}

double Graph::squaredCartesianDistance (nodeInfo* point1, const nodeInfo* point2) {
    return (pow(point1->lon-point2->lon,2)+pow(point1->lat-point2->lat,2));
}



