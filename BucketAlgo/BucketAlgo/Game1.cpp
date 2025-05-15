#include "Game1.h"
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
void Game1::buildG()
{

    for (int i = 0; i <= _l; ++i) {
        for (int j = 0; j <= _s; ++j) {
            Vertex u = { i, j };

            // Empty large jug
            if (i > 0)
                _gL.AddEdge(u, { 0, j });

            // Empty small jug
            if (j > 0)
                _gL.AddEdge(u, { i, 0 });

            // Fill large jug
            if (i < _l)
                _gL.AddEdge(u, { _l, j });

            // Fill small jug
            if (j < _s)
                _gL.AddEdge(u, { i, _s });

            // Pour from large to small
            if (i > 0 && j < _s) {
                int amount = std::min(i, _s - j);
                _gL.AddEdge(u, { i - amount, j + amount });
            }

            // Pour from small to large
            if (j > 0 && i < _l) {
                int amount = min(j, _l - i);
                _gL.AddEdge(u, { i + amount, j - amount });
            }
        }
    }
}


// BFS from 'start' to 'goal' on _gL, returning the path of vertices
std::vector<Vertex> Game1::BFS(const Vertex& start, const Vertex& goal) {
    // Use ordered maps instead of unordered_map + hash
    std::map<Vertex, bool>       visited;
    std::map<Vertex, Vertex>     parent;
    std::queue<Vertex>           q;

    // Initialize
    visited[start] = true;
    q.push(start);

    bool found = false;
    while (!q.empty()) {
        Vertex u = q.front(); q.pop();
        if (u == goal) {
            found = true;
            break;
        }
        // For each neighbor v of u
        for (auto& v : _gL.GetAdjList(u)) {
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    // Reconstruct path if goal was reached
    std::vector<Vertex> path;
    if (!found) return path;  // empty => no solution

    for (Vertex cur = goal; cur != start; cur = parent[cur]) {
        path.push_back(cur);
    }
    path.push_back(start);
    std::reverse(path.begin(), path.end());
    return path;
}



