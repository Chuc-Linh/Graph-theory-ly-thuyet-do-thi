#include<iostream>
#include<vector>
#include<queue>
#include <algorithm>
using namespace std;

int n,m;
vector<int> adj[100];
int parent[100];

void dsc()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(parent,-1, sizeof(parent));
}
int Check(int u)
{
	queue <int> a;
	a.push(u);
	parent[u]=0;
	while(!a.empty())
	{
		int v=a.front();
		a.pop();
		for(int x:adj[v])
		{
			if(parent [x] ==-1)
			{
				parent[x] =1 - parent[v];
				a.push(x);
			}
	// nếu đồ thị 2 nút cùng màu thì k là đồ thị 2 phía
			else if(parent [x] == parent[v])
			{
				return 0;
			}
		}
	}
	return 1;
}
int main()
{
	dsc();
	if(!Check(1))
		cout<<" NOT Bipartite Graph";
		else cout<< "It's a Bipartite Graph";
	return 0;

}

