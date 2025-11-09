#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1000;
vector<int> adj[MAXN];
bool visited[MAXN];
int parent[MAXN];
int n, m;

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            parent[v] = u;  // lưu cha của v là u
            dfs(v);
        }
    }
}

int main() {
    cout << "Nhap so dinh va so canh: ";
    cin >> n >> m;

    cout << "Nhap cac canh (u v):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Gán cha mặc định = -1
    for (int i = 1; i <= n; i++) parent[i] = -1;

    dfs(1); // bắt đầu từ đỉnh 1

    cout << "\nCay khung DFS:\n";
    for (int i = 1; i <= n; i++) {
        if (parent[i] != -1)
            cout << i << " <- " << parent[i] << endl;
    }

    return 0;
}
