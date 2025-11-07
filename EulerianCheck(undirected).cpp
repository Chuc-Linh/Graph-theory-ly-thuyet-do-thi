#include<iostream>
#include<vector>
#include<set>
using namespace std;
int n,m;
set <int> adj[100];
bool visited[100];
int degree[100];

// the input is a Edge List
void dfs(int u)
{
	visited [u] =true;
	for(int i:adj[u])
	{
		if(!visited[i])
		dfs(i);
	}
}

// check connectivity of the graph
int connectedcomponent()
{
	int cnt =0;
	memset(visited,false,sizeof(visited));
	for(int i=1;i<=n;i++)
	{
		if(!visited[i])
	{
		++cnt;
		dfs(i);
	}
}
	if(cnt ==1 ) return 1;
	return 0;
}

// calculating the degree of a vertex.
int tinhdegree(int u)
{
	int tong=0;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y; 
		cin>>x>>y;
		adj[x].insert(y);
		adj[y].insert(x);
		degree[x]++;
		degree[y]++;
	}
	for(int x=1;x<=n;x++)
	{
		if(degree[x]%2==0)
		tong++;
	}

	if(tong == n) return 1;
	return 0;
}
void find(int u)
{
	stack<int> st;
	vector<int> ec; 
	st.push(u);
	while(!st.empty())
	{
		int c=st.top();
		if(adj[c].size()!=0)
		{
			// lấy phần tử đầu tiên trong danh sách đỉnh kề với c
			int d=*adj[c].begin();
			st.push(d);
			adj[c].erase(d);
			adj[d].erase(c);
		}
		else {
			st.pop();
			ec.push_back(c);
		}
	}
	for(int i:ec) cout<<i<<" ";
}
int main()
{
	int Degree = tinhdegree(1);
	int connected = connectedcomponent();
	if(Degree&& connected) 
	{
		cout<<"That's an Eulerian Circle"<<endl;
		cout<<"Eulerian Circle is: ";
		find(1);
	}
	else cout<<" Not Eulerian Circle";

	return 0;
}





