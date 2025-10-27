#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1000;
vector<int> adj[MAXN];
bool visited[MAXN];
int n, m;

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) dfs(v);
    }
}

bool IsTree() {
    // Điều kiện 1: số cạnh = n - 1
    if (m != n - 1) return false;

    // Điều kiện 2: đồ thị phải liên thông
    dfs(1);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) return false; // có đỉnh chưa thăm -> không liên thông
    }

    return true;
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

    if (isTree()) cout << "Do thi la mot cay.\n";
    else cout << "Do thi khong phai la cay.\n";

    return 0;
}
