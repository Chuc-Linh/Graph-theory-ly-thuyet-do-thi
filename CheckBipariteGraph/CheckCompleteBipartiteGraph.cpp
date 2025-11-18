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
int BFS(int u)
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
			else if(parent [x] == parent[v]) return 0;
		}
	}
	return 1;
}
int checkComplete( )
{
	vector <int>A,B;
	for(int i=1;i<=n;i++)
		{
			if(parent[i]==0) A.push_back(i);
			else  B.push_back(i);
		}
	bool complete= true;
	// có thể in ra các đỉnh ở 2 phía ở từ code này
	for (int u : A){ if (adj[u].size() != B.size()) complete = false;}
    for (int u : B){ if (adj[u].size() != A.size()) complete = false;}
	return true;
}
int main()
{
	dsc();
	if(!BFS(1))
		cout<<" NOT Bipartite Graph";
	else if(CheckComplete())
		 cout<< "It's a Complete Bipartite Graph";
	else cout <<"It's a Bipartite Graph";
	return 0;

}

