#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <list>
#include <map>
#include <utility>
#include <algorithm>

using std::pair;
using std::vector;
using std::list;
using std::map;

using Vertex = std::pair<int, int>;

class GraphList {
private:
    map<Vertex, list<Vertex>> adjList;

public:

    void MakeEmptyGraph(int maxLarge, int maxSmall);
    void AddEdge(const Vertex& u, const Vertex& v);
    list<pair<int, int>> GetAdjList(const Vertex& u) const;
};

#endif
