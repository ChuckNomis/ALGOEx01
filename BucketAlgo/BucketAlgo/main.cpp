#include "Game1.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int capLarge = 4;
    int capSmall = 3;

    // Create Game1 instance with capacities
    Game1 game(capLarge, 0, capSmall); // _l = capL+1, _w = unused, _s = capS+1
    game.buildG();  // Build the state graph

    // Print adjacency list for a few selected states
    vector<Vertex> testStates = {
        {0, 0},
        {0, 3},
        {2, 1}
    };

    cout << "=== Adjacency List Tests ===" << endl;
    for (const auto& state : testStates) {
        auto neighbors = game._gL.GetAdjList(state);
        cout << "Neighbors of (" << state.first << "," << state.second << "): ";
        for (const auto& n : neighbors) {
            cout << "(" << n.first << "," << n.second << ") ";
        }
        cout << endl;
    }

    // Test BFS from (0,0) to (2,0)
    Vertex start{ 0, 0 };
    Vertex goal{ 2, 0 };

    auto path = game.BFS(start, goal);
    cout << "\n=== BFS Test: Path from (0,0) to (2,0) ===" << endl;

    if (path.empty()) {
        cout << "No path found." << endl;
    }
    else {
        cout << "Path found in " << path.size() - 1 << " steps:" << endl;
        for (const auto& v : path) {
            cout << "(" << v.first << "," << v.second << ") ";
        }
        cout << endl;
    }

    return 0;
}
