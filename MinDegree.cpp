#include <iostream>
#include <fstream>
#include <map>
#include<vector>
#include <set>
using namespace std;

 	int n, m;
 	vector<int> indeg;
    map<int, set<int>> adj;
    
int docfile()
{

	ifstream fin("cohuong.txt");
    if (!fin.is_open()) {
        cout << "Không mở được file!" << endl;
        return -2;
    }
    fin >> n >> m;  
    indeg.assign(n + 1, 0);
	for (int i = 1; i <= n; i++) {
        indeg[i] = 0;
    }
	for (int i = 0; i < m; i++) {
        int u, v;
        fin >> u >> v;
        if(u<0||v<0)
        	return -1;
        else {
        	indeg[u]++; 
        	indeg[v]++;
		}     
}
	fin.close();
	int minDeg = indeg[1]; // khong the indeg[0] dc vi gtr root la 1 :))
	    for (int i = 2; i <= n; i++) {
	        if (indeg[i] < minDeg)
	            minDeg = indeg[i];
	    }
	
	    return minDeg;
	}
int main() {
    int result= docfile();
	if (result == -1)
        cout << "Co dinh co don!";
    else if (result == -2)
        cout << "khong the mo file";
    else
        cout << "Bac nho nhat la: " << result << endl;
    return 0;
}
