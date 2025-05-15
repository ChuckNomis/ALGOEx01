#include "GraphLists.h"
void GraphList::MakeEmptyGraph(int maxLarge, int maxSmall) {
    adjList.clear();
    for (int i = 0; i <= maxLarge; ++i) {
        for (int j = 0; j <= maxSmall; ++j) {
            Vertex vertex = { i, j };
            adjList[vertex] = list<Vertex>();
        }
    }
}

void GraphList::AddEdge(const Vertex& u, const Vertex& v) {
    adjList[u].push_back(v);
}

list<Vertex> GraphList::GetAdjList(const Vertex& u) const {
    auto it = adjList.find(u);
    if (it == adjList.end()) {
        return {};
    }

    // Sort lexicographically before returning
    list<Vertex> sortedList = it->second;
    sortedList.sort();
    return sortedList;
}