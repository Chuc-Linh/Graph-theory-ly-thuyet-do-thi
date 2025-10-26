#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> path;
vector<int> visited;
bool foundCycle = false;

// Hàm đệ quy kiểm tra Hamilton
void hamilton(int pos, int count, int start) {
    if (foundCycle) return; // nếu đã tìm thấy thì dừng
    if (count == n && adj[pos][start] == 1) {
        foundCycle = true;
        cout << "Chu trinh Hamilton tim thay: ";
        for (int v : path) cout << v << " ";
        cout << start << "\n";
        return;
    }

    for (int v = 1; v <= n; ++v) {
        if (!visited[v] && adj[pos][v] == 1) {
            visited[v] = 1;
            path.push_back(v);
            hamilton(v, count + 1, start);
            visited[v] = 0;
            path.pop_back();
        }
    }
}

int main() {
    cin >> n >> m;
    adj.assign(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = adj[v][u] = 1; // đồ thị vô hướng
    }

    visited.assign(n + 1, 0);
    path.clear();
    int start = 1;
    visited[start] = 1;
    path.push_back(start);

    hamilton(start, 1, start);

    if (!foundCycle)
        cout << "Khong ton tai chu trinh Hamilton trong do thi.\n";

    return 0;
}
