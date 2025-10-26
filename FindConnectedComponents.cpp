#include <bits/stdc++.h>
using namespace std;

int main() {
	
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        // vô hướng
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n+1, 0);
    vector<vector<int>> components;

    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            // DFS ngầm bằng stack (tránh recursion sâu)
            vector<int> comp;
            stack<int> st;
            st.push(i);
            vis[i] = 1;
            while (!st.empty()) {
                int u = st.top(); st.pop();
                comp.push_back(u);
                for (int v : adj[u]) {
                    if (!vis[v]) {
                        vis[v] = 1;
                        st.push(v);
                    }
                }
            }
            components.push_back(comp);
        }
    }

    cout << components.size() << '\n';
    for (size_t i = 0; i < components.size(); ++i) {
        // in từng thành phần
        cout << "Component " << i+1 << " (" << components[i].size() << "):";
        for (int x : components[i]) cout << ' ' << x;
        cout << '\n';
    }
    return 0;
}
