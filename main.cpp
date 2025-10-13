#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool isBipartite(const std::vector<std::vector<int>>& graph) {
    int n = graph.size();
    if (n == 0) {
        return true;
    }

    // Use -1 to indicate no color, 0 for the first color, 1 for the second.
    // The vector is correctly sized to the number of nodes.
    std::vector<int> color(n, -1);

    // Loop through every node in the graph.
    for (int start_node = 0; start_node < n; ++start_node) {
        // If the node has not been colored yet, it's part of a new component.
        // Start a BFS from this node.
        if (color[start_node] == -1) {
            std::queue<int> q;
            q.push(start_node);
            color[start_node] = 0; // Start coloring with color 0.

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : graph[u]) {
                    // If an adjacent node has the same color, it's not bipartite.
                    if (color[v] == color[u]) {
                        return false;
                    }

                    // If the adjacent node is not yet colored, color it with the
                    // opposite color and add it to the queue.
                    if (color[v] == -1) {
                        color[v] = 1 - color[u]; // A clever trick to flip 0 to 1 and 1 to 0.
                        q.push(v);
                    }
                }
            }
        }
    }

    // If all components are checked and no conflicts were found, the graph is bipartite.
    return true;
}

void test()
{
    int G[1][1] = {{1}};
    int n = 1;

    vector<vector<int>> graph(n, vector<int>());
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (G[i][j])
                graph[i].push_back(j);
        }
    }

    isBipartite(graph) ? cout << "Yes" : cout << "No";
    // cout << endl;
}

int main()
{
    test();
    return 0;
}