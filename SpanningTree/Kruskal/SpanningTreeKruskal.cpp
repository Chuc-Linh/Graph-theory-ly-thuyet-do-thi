#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
    bool operator<(const Edge &other) const {
        return w < other.w;
    }
};

vector<int> parent, sz;

int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

bool union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (auto &e : edges) cin >> e.u >> e.v >> e.w;

    sort(edges.begin(), edges.end());
    parent.resize(n + 1);
    sz.assign(n + 1, 1);
    for (int i = 1; i <= n; i++) parent[i] = i;

    vector<Edge> mst;
    int total = 0;
	int tong=0;
    for (auto &e : edges) {
        if (union_set(e.u, e.v)) {
            mst.push_back(e);
            total += e.w;
            tong++;
            if (tong == n - 1) break;
        }
    }
	if (tong < n - 1) {
        cout << "Do thi khong lien thong\n";
        return 0;
    }
    cout << "Cay khung nho nhat (Kruskal):\n";
    for (auto &e : mst)
        cout << e.u << " - " << e.v << " : " << e.w << "\n";
    cout << "Tong trong so: " << total << "\n";
     cout << "So canh trong cay khung: " << tong << "\n";
}
