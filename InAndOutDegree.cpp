#include <iostream>
#include <fstream>
#include<vector>

using namespace std;

int main() {
    ifstream fin("cohuong.txt");
    if (!fin.is_open()) {
        cout << "Không mở được file!" << endl;
        return 1;
    }

    int n, m;
    fin >> n >> m;
    
   vector<int> indeg(n+1,0);
    vector<int>outdeg(n+1,0);

    for (int i = 0; i < m; i++) {
        int u, v;
        fin >> u >> v;
        
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




