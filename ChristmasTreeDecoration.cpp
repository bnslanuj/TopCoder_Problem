#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<queue>
#include<map>
#include<stack>
#include<vector>
#include<ctime>
#include<cstring>
#include<algorithm>
#include<set>
#include <iomanip>
#include<cmath>
#define ll long long
#define mod 1000000007
using namespace std;

class disjoint
{
	int *par,*rank;
	public:
		disjoint(int n)
		{
			par=(int*)malloc(sizeof(int)*(n+1));
			rank=(int*)malloc(sizeof(int)*(n+1));
			for(int i=0;i<n;i++)
			{
				par[i]=i;
				rank[i]=0;
			}
		}
		int find(int i)
		{
			if(par[i]!=i)
				par[i]=find(par[i]);
			return par[i];
		}
		void link(int x,int y)
		{
			x=find(x);
			y=find(y);
			if(rank[x]<rank[y])
				par[x]=y;
			else if(rank[x]>rank[y])
				par[y]=x;
			else
			{
				rank[x]++;
				par[y]=x;
			}
			return ;
		}
};
class ChristmasTreeDecoration
{
	public:
		int solve(vector <int> col, vector <int> x, vector <int> y)
		{
			disjoint DS(col.size());
			int c=0;
			for(int i=0;i<x.size();i++)
			{
				if(col[x[i]-1]!=col[y[i]-1] && DS.find(x[i])!=DS.find(y[i]))
				{
					c++;
					DS.link(x[i],y[i]);
				}
			}
			return col.size()-1-c;
		}
};
int main()
{
	return 0;
}
