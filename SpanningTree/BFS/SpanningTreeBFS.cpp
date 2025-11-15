#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<bool> visited;
vector<pair<int,int>> treeEdges;

void BFS_Tree(int start) {
    queue<int> q;
    // đếm cạnh của khung cây
    int count =0;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                treeEdges.push_back({u, v}); // cạnh thuộc cây khung
                count=count+1;
                q.push(v);
            }
        }
    }
    cout<<count<<endl;
}

int main() {
    cin >> n >> m;
    // dùng assign khi có vector nếu mà chỉ bool thì dùng memset 
    adj.assign(n+1, {});
    visited.assign(n+1, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    BFS_Tree(1);
    for (auto [u, v] : treeEdges)
        cout << u << " - " << v << "\n";

    return 0;
}

