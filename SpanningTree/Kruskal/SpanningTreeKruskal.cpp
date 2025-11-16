#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};
vector<int> parent;
vector<int> sz;
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
bool cmp(const Edge &a, const Edge &b) {
    return a.w < b.w;
}

int main() {
    int n, m;
	cin >> n >> m;
	int total = 0;
	int tong=0;
    vector<Edge> edges(m);
	vector<Edge> mst;
    for (auto &e : edges) cin >> e.u >> e.v >> e.w;
    parent.resize(n + 1);
    sz.assign(n + 1, 1);
	
	sort(edges.begin(), edges.end(),cmp);
    for (int i = 1; i <= n; i++) parent[i] = i;
	
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
    for (auto &e : mst){
    cout << e.u << " - " << e.v << " : " << e.w << "\n";}
    cout << "Tong trong so: " << total << "\n";
    cout << "So canh trong cay khung: " << tong << "\n";
return 0;
}