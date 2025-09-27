#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

void docfile(ifstream &file, vector<vector<int>> &a)
{
	int sodinh;
	a.resize(sodinh,vector<int>(sodinh));
	file.open("vohuongcohuongmatran.txt");
	file>>sodinh;
	a.resize(sodinh,vector<int>(sodinh));
	for(int i=0;i<sodinh;i++)
	{
		for(int j=0;j<sodinh;j++)
		{
			file>> a[i][j];
		}
	}
}
int ktrdothivohuongcohuong(vector<vector<int>> a)
{
	for(int i=0;i<a.size();i++)
	{
		for(int j=0;j<a.size();j++)
		{
			if(a[i][j]!=a[j][i]) return 0;// vo huong
		}
	}
	return 1;//co huong
}
int main()
{
	vector<vector<int>> a;
	ifstream file;
	docfile(file,a);
	cout<<ktrdothivohuongcohuong(a);
	file.close();
	return 0;
}