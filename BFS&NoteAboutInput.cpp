#include<iostream>
#include<vector>
#include<queue>
#include <cstring>
using namespace std;

/* khi đầu vào dữ liệu khác nhau như ma trận kề, danh sách cạnh, danh sách kề thì thuật toán DFS và BFS sẽ không đổi nhưng cách đọc sẽ khác nhau. 
CHúng ta sẽ đổi về danh sách kề hết để thực hiện đc đồng bộ hơn nek
+ Bài ở dưới là danh sách cạnh thì cậu có 2 cách để lưu
	- dùng vector<vector<int>> adj[]; khi không trọng số
	- dùng vector<pair<int,int>> adj[]; khi có trọng số
+ Đối với ma trận kề
			file>>n;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					int x;file>>x;
					if(x==1){
						adj[i].push_back(j);
						adj[j].push_back(i);
					}
				}
			}
Thường người ta sẽ cho đọc từ file ha thế mik sẽ đọc thế nào cho ổn nek
+ Đối với danh sách cạnh thì thay vì mik cin>>x>>y đổi thành file>>x>>y nhưng nếu nó không cho mik số cạnh ban đầu thì mik duyệt hết file 
		while (file >> u >> v) {   // đọc đến hết file
		        adj[u].push_back(v);
		        adj[v].push_back(u); // nếu vô hướng, có hướng thì bỏ
		    }
CÒn đây là khi có số cạnh 
		file >> n >> m;
		    for (int i = 0; i < m; i++) {
		        int u, v; in >> u >> v;
				// dung vector
		        adj[u].push_back(v);
		        adj[v].push_back(u); //  nếu vô hướng, có hướng thì bỏ
		    }
+ Đôi với danh sách kề
		    string line;
		    for (int i = 1; i <= n; i++) {
		        getline(in, line);
		        stringstream ss(line);
		        int v;
		        while (ss >> v)
				{
					adj[i].push_back(v);
					adj[v].push_back(i); //khi đề chỉ cho 1 chiều và bỏ khi cho 2 chiều và *có hướng*
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






