#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void bfs(vector<vector<int>> graph, int start) {
    vector<bool> isVisited(graph.size(), 0);
    // for (bool x: isVisited) cout << x << " ";
    queue<int> q;
    // Init
    cout << start << " ";
    q.push(start);
    isVisited[start] = 1;
    // for (bool x: isVisited) cout << x << " ";
    // Iteration
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for (int x : graph[curr]){
            if (isVisited[x] == 0){
                q.push(x);
                cout << x << " ";
                isVisited[x] = 1;
            }
        }
    }

}

int main()
{
    int init_graph[10][10] = {{0, 1, 1, 0, 1, 0, 1, 0, 1, 0},
                              {0, 0, 1, 1, 0, 0, 0, 1, 0, 0},
                              {0, 1, 0, 0, 0, 1, 1, 0, 1, 1},
                              {1, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                              {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
                              {1, 0, 1, 0, 1, 0, 0, 0, 1, 0},
                              {0, 0, 1, 1, 0, 1, 0, 0, 0, 0},
                              {1, 0, 0, 0, 0, 1, 1, 0, 1, 0},
                              {0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
                              {1, 0, 1, 0, 1, 0, 0, 0, 1, 0}};
    int n = 10;
    vector<vector<int>> graph(n, vector<int>());
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (init_graph[i][j])
                graph[i].push_back(j);
        }
    }
    for (int i = 0; i < 10; i++){
        cout << i << ": ";
        for (size_t j = 0; j < graph[i].size(); j++) cout << graph[i][j] << " ";
        cout << endl;

    }
    bfs(graph,0);
    return 0;
}