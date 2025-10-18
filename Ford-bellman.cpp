#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
    int w;
};

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    vector<Edge> edges;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        edges.push_back({v, u, w}); 
    }

    vector<int> d(n + 1, 1e9);
    vector<int> pre(n+1,-1); // mảng lưu đỉnh trước

    d[s] = 0;

    // Thuật toán Bellman–Ford
    for (int i = 1; i <= n - 1; i++) {
        bool any = false;
        for (auto &e : edges) {
            if (d[e.u] != 1e9 && d[e.v] > d[e.u] + e.w) {
                d[e.v] = d[e.u] + e.w;
                pre[e.v] = e.u; // lưu lại đường đi
                any = true;
            }
        }
        if (!any) break;
    }

    // Kiểm tra chu trình âm
    for (auto &e : edges) {
        if (d[e.u] != 1e9 && d[e.v] > d[e.u] + e.w) {
            cout << "Negative cycle detected\n";
            return 0;
        }
    }

    if (d[t] == 1e9) {
        cout << "No path\n";
        return 0;
    }

    // Truy vết đường đi
    vector<int> path;
    for (int v = t; v != -1; v = pre[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());

    cout << "Shortest distance from " << s << " to " << t << " is: " << d[t] << "\n";
    cout << "Path: ";
    for (int v : path) cout << v << " ";
    cout << "\n";

    return 0;
}
