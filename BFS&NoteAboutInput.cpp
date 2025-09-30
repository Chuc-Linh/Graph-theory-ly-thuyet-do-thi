#include<iostream>
#include<vector>
#include<queue>
#include <cstring>
using namespace std;

/* khi đầu vào dữ liệu khác nhau như ma trận kề, danh sách cạnh, danh sách kề thì thuật toán DFS và BFS sẽ không đổi nhưng cách đọc sẽ khác nhau:
+ bài ở dưới là danh sách cạnh 
+ Đối với ma trận kề với n là số đỉnh: thì điều kiện lấy đỉnh như sau:
	for (int v = 1; v <= n; v++) {
            if (a[u][v] == 1 && !visited[v]) {
				 q.push(v);
                visited[v] = true;
			}
		}
	for (int v = 1; v <= n; v++) {
        if (a[u][v] == 1 && !visited[v]) {
            DFS(v);
	+ ĐỐi với danh sách kề thì chúng ta xem cái ở dưới nhe

			
Thường người ta sẽ cho đọc từ file ha thế mik sẽ đọc thế nào cho ổn nek
+ Đối với danh sách cạnh thì thay vì mik cin>>x>>y đổi thành file>>x>>y nhưng nếu nó không cho mik số cạnh ban đầu thì mik duyệt hết file 
		while (file >> u >> v) {   // đọc đến hết file
		        adj[u].push_back(v);
		        adj[v].push_back(u); // nếu vô hướng
		    }
CÒn đây là khi có số cạnh 
		file >> n >> m;
		    for (int i = 0; i < m; i++) {
		        int u, v; in >> u >> v;
		        adj[u].push_back(v);
		        adj[v].push_back(u); // vô hướng
		    }
+ Đôi với danh sách kề
		    string line;
		    getline(in, line); // bỏ dòng số đỉnh
		
		    for (int i = 1; i <= n; i++) {
		        getline(in, line);
		        stringstream ss(line);
		        int v;
		        while (ss >> v) adj[i].push_back(v);
				}
+ Đối với ma trận kề thì cứ bth 
			for (int i = 1; i <= n; i++) {
        		for (int j = 1; j <= n; j++) {
           			 file >> a[i][j];
        }
    }
	
	*/
	int n,m;
	vector<int> adj[100];
 	bool visited[100];

void dsk()
{
	cout<<"nhap so dinh, so canh (cach nhau boi dau cach): ";
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{	
		cout<<"nhap cac dinh ke voi dinh "<<i+1<<"(vd nhu 1 3 hay 1 4): ";
		int x,y; cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(visited, false, sizeof(visited));
}
void bfs(int u)
{
	// buoc khoi tao queue rong
	queue<int> q;
	q.push(u);
	visited[u] = true;
	//buoc lap
	while(!q.empty())
	{
		int v =q.front();
		q.pop();
		cout<<v<<" ";
		for(int x:adj[v])
		{
			if(!visited[x])
			{
				q.push(x);
				visited[x]=true;
			}
			
		}
	}
}
int main()
{
	dsk();
	bfs(1);
	return 0;

}
