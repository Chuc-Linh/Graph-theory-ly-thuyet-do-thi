#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int dinh,canh, di,den;
vector<int> adj[100];
bool visited[100];
int parent[100];
 
// use recursion
void DFS(int u)
{
	visited[u] = true;
	for(int v:adj[u])
	{
		if(!visited[v])
		{
			parent[v] = u;
			DFS(v);
		}
	}
}

void Path(int di, int den)
{
	memset(visited,false, sizeof(visited ));
	memset(parent,0,sizeof(parent));
	DFS(di);
	if(!visited[den])
	{
		cout<<" khong co duong di";
	}
	else 
	{
		vector<int> path;
		while(den!=di)
		{
			path.push_back(den);
			den =parent[den];
		}
		path.push_back(di);
		reverse(path.begin(),path.end());
		for(int x:path)
		{
			cout<<x<<" ";
		}
	}
}
int main()
{
		cin>>dinh>>canh;
	for(int i=0;i<canh;i++)
	{
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	cin>>di>>den;
	Path(di,den);
	
	return 0;
}