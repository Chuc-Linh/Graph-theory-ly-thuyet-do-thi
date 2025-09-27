#include<iostream>
#include<vector>
#include<queue>
#include <cstring>
using namespace std;


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