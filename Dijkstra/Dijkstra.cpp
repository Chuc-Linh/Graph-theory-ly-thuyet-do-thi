#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include <algorithm> 
using namespace std;
int n,m,s,t;
int pre[100];
vector<pair<int,int>> adj[100];
void doc()
{
	ifstream file;
	file.open("inputDijkstra.txt");
	file>>n>>m>>s>>t;
	for(int i=1;i<=m;i++)
	{
		int x,y,z; file>>x>>y>>z;
		adj[x].push_back({y,z});
	}
}

void Dijkstra(int s, int t)
{
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> p;
	vector<long long> d(n+1,1e9);
	d[s]=0;
	pre[s]=s;
	p.push({0,s});
	while(!p.empty())
	{
		pair<int,int> top = p.top();
		p.pop();
		int kc = top.first;// kc
		int u = top.second;//dinh
		if(kc>d[u]) continue;
		for(auto i:adj[u])
		{
			int v = i.first;
			int w = i.second;
			if( d[v]>d[u]+w)
				{
					d[v]=d[u]+w;
					p.push({d[v],v});
					pre[v]=u;
				}
				
		}
	}
	cout<<d[t]<<endl;
	vector<int>path;
	while(1)
	{
		path.push_back(t);
		if(t==s) break;
		t=pre[t];
	}
	reverse(begin(path),end(path));
	for(int x:path)
	{
		cout<<x<<" ";
	}
}
int main()
{
	doc();
	Dijkstra(s,t);
	return 0;

}
