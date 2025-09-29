#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

void docfile(ifstream &file, vector<vector<int>> &a)
{
	int sodinh;
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

int tongcanhmatran(vector<vector<int>> a)
{
	int dem=0;
for(int i=0;i<a.size();i++)
	{
		for(int j=0;j<a.size();j++)
		{
			// canh khuyen thi la khac 0 tai duong cheo
			if(a[i][j]!=0 || a[i][i]==1) dem++;
		}
	}
	return dem;
}

int main()
{
	ifstream file;
	vector<vector<int>>a;
	docfile(file,a);
	cout<<tongcanhmatran(a);
	return 0;

}
