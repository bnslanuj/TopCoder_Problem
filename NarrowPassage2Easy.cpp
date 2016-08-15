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

class NarrowPassage2Easy
{
	void swap(pair<int,int>&a,pair<int,int>&b)
	{
		pair<int,int>t=a;
		a=b;
		b=t;
	}
	void fun(set<vector<pair<int,int> > >&s,vector<pair<int,int> >&a,int sum)
	{
		for(int i=1;i<a.size();i++)
		{
			if(a[i].first+a[i-1].first<=sum)
			{
				swap(a[i],a[i-1]);
				if(s.find(a)==s.end())
				{
					s.insert(a);
					fun(s,a,sum);
				}
				swap(a[i],a[i-1]);
			}
		}
		return ;
	}
	public:
		int count(vector <int> size, int maxSizeSum){
			vector<pair<int,int> >s(size.size());
			set<vector<pair<int,int> > >se;
			for(int i=0;i<size.size();i++)
				s[i]=make_pair(size[i],i);
			se.insert(s);
			fun(se,s,maxSizeSum);
			return se.size();
		
		}	
};
int main()
{
	return 0;
}
