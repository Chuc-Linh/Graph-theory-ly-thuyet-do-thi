#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
int n,m;
bool visited[100];
int a[10][10];
int deg[10];

// the input is a matrix
void docfile()
{
	ifstream file;
	file.open("semi.txt") ;
	file>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			file>>a[i][j];
		}
	}
}
void dfs(int u)
{
	visited[u]=true;
	for(int i=1;i<=n;i++)
	{
		if(!visited[i]&& a[u][i]==1)
			{
				dfs(i);
			}
			
	}
}
int connectedcomponent()
{
	int cnt=0;
	memset(visited,false,sizeof(visited));
	for(int i=1;i<=n;i++){
		if(!visited[i])
	{
		cnt++;
		dfs(i);
	}
	}
	
	if(cnt==1) return 1;
	return 0;
}

int degree()
{
	int degr = 0;
	for (int i = 1; i <= n; i++)
	{
		for(int j=1;j<=n;j++)
		{
			if (a[i][j] == 1)
				deg[i]++;
		}
		if (deg[i]%2!=0)		
				degr++;
	}
	if(degr==2) return 1;
	else if(degr==0) return -1;
	return 0;
}

int main()
{
	docfile();
	if(connectedcomponent()&&degree())
		cout<<"It's a Semi Eulerian circle";
	else if(connectedcomponent()&&degree()==-1)
	cout<<"It's an Eulerian circle";
	else cout<<"It's not a semi Eulerian circle";
	return 0;
}