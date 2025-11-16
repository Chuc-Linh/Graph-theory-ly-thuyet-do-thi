#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int n, m;            // số đỉnh, số cạnh
int s, t;            // source, sink
vector<vector<int>> cap;     // capacity (residual)
vector<vector<int>> adj;     // adjacency list

// DFS tìm đường tăng
int dfs(int u, int flow, vector<bool> &vis, vector<int> &parent) {
    if (u == t) return flow;

    vis[u] = true;

    for (int v : adj[u]) {
        if (!vis[v] && cap[u][v] > 0) {
            parent[v] = u;
            int pushed = dfs(v, min(flow, cap[u][v]), vis, parent);
            if (pushed > 0) return pushed;
        }
    }
    return 0;
}

// Ford–Fulkerson
int maxflow() {
    int flow = 0;

    while (true) {
        vector<bool> vis(n, false);
        vector<int> parent(n, -1);

        int pushed = dfs(s, INF, vis, parent);
        if (pushed == 0) break;  // hết đường tăng

        flow += pushed;

        // Cập nhật residual graph
        int v = t;
        while (v != s) {
            int u = parent[v];
            cap[u][v] -= pushed;   // forward giảm
            cap[v][u] += pushed;   // backward tăng
            v = u;
        }
    }

    return flow;
}

// BFS để tìm tập reachable (dùng cho min-cut)
vector<bool> getReachable() {
    vector<bool> vis(n, false);
    queue<int> q;

    vis[s] = true;
    q.push(s);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (!vis[v] && cap[u][v] > 0) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
    return vis;
}

int main() {
    cin >> n >> m >> s >> t;

    cap.assign(n, vector<int>(n, 0));
    adj.assign(n, vector<int>());

    cout << "=== Reading edges ===\n";
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;

        adj[u].push_back(v);
        adj[v].push_back(u);  // residual graph
        cap[u][v] += c;       // gộp capacity nếu có multi-edge
    }

    // Tính max flow
    int mf = maxflow();
    cout << "\n===== MAX FLOW = " << mf << " =====\n\n";

    // In residual graph cuối
    cout << "===== RESIDUAL GRAPH (u -> v : remaining cap) =====\n";
    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) {
            if (cap[u][v] > 0)
                cout << u << " -> " << v << " : " << cap[u][v] << "\n";
        }
    }

    // Tìm min cut
    vector<bool> reach = getReachable();

    cout << "\n===== MIN CUT EDGES =====\n";
    int cutVal = 0;

    for (int u = 0; u < n; u++) {
        if (reach[u]) {
            for (int v : adj[u]) {
                if (!reach[v] && cap[u][v] == 0) {
                    // cạnh gốc đã đầy ⇒ thuộc min cut
                    // cần lấy capacity gốc ⇒ cap[v][u] = backward flow = flow đã đẩy
                    int originalCap = cap[v][u];
                    cutVal += originalCap;
                    cout << u << " -> " << v << "  (capacity " << originalCap << ")\n";
                }
            }
        }
    }

    cout << "\nMin cut value = " << cutVal << "\n";

    return 0;
}
