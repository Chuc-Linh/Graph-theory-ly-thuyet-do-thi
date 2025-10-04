#include <iostream>
#include <fstream>
#include <map>
#include <set>
using namespace std;

int main() {
    ifstream fin("cohuong.txt");
    if (!fin.is_open()) {
        cout << "Không mở được file!" << endl;
        return 1;
    }

    int n, m;
    fin >> n >> m;

    map<int, set<int>> adj; // danh sách kề: u -> {v}
    map<int, int> indeg, outdeg; // bậc vào, bậc ra

    for (int i = 1; i <= n; i++) {
        indeg[i] = 0;
        outdeg[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        fin >> u >> v;
        adj[u].insert(v);

        // cập nhật bậc
        outdeg[u]++;
        indeg[v]++;
    }

    fin.close();

    cout << "\n=== Ban bac ra / vao ===\n";
    for (int i = 1; i <= n; i++) {
        cout << "Dinh " << i 
             << ": ra = " << outdeg[i] 
             << ", vao = " << indeg[i] << endl;
    }

    return 0;
}
