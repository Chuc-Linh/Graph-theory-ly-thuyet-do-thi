#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
    int w;
};
int n, m, s, t;
int u, v, w;
vector<Edge> edges;
void docfile()
{
	 ifstream file;
	 file.open("mau.txt");
	 file >> n >> m >> s >> t;
	 for (int i = 0; i < m; i++) {
       
        file >> u >> v >> w;
        edges.push_back({u, v, w});
        edges.push_back({v, u, w}); 
    }
}
int main() {
    docfile();
    vector<int> d(n + 1, 1e9);
    vector<int> pre(n+1,-1); 

    d[s] = 0;
    // Thuật toán Bellman–Ford
	// vì đường đi ngắn nhất giữa 2 đỉnh bất  thì đường đi sẽ không lớn hơn n-1 
    for (int i = 1; i <= n - 1; i++)
		{
	// biến bool này là để dừng lại nếu  đi ngắn nhất ổn định không có gì thay đổi thì nó sẽ dừng sớm
        bool any = false;
        for (auto e : edges) {
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


