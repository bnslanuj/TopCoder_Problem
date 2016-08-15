#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<queue>
#include<map>
#include<stack>
#include<vector>
#include<ctime>
#include<string>
#include<algorithm>
#include <iomanip>
#include<cmath>
#define ll long long
#define mod 1000000007
using namespace std;



class PairGameEasy
{
	public:
		string able(int a, int b, int c, int d)
		{
			queue<pair<int,int> >q;
			map<pair<int,int>,int>v;
			bool found=false;
			q.push(make_pair(a,b));
			
			while(!q.empty())
			{
				pair<int,int> ret=q.front();
				q.pop();
				
				if(ret.first==c && ret.second==d)
				{
					found=true;
					break;
				}
				
				if(ret.first+ret.second<=c && v[make_pair(ret.first+ret.second,ret.second)]==0)
				{
					v[make_pair(ret.first+ret.second,ret.second)]=1;
					q.push(make_pair(ret.first+ret.second,ret.second));
				}
				
				if(ret.first+ret.second<=d && v[make_pair(ret.first,ret.first+ret.second)]==0)
				{
					v[make_pair(ret.first,ret.first+ret.second)]=1;
					q.push(make_pair(ret.first,ret.first+ret.second));
				}
				
			}
			
			if(found)return "Able to generate";
			return "Not able to generate";
		}
};
