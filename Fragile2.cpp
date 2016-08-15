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

class Fragile2
{
	int find(vector<string>&graph,vector<int>&v)
	{
		int c=0;
		for(int i=0;i<graph.size();i++)
		{
			if(v[i])continue;
			
			queue<int>q;
			q.push(i);
			c++;
			while(!q.empty())
			{
				int curr=q.front();
				v[curr]=1;
				q.pop();
				for(int i=0;i<graph.size();i++)
				{
					if(graph[curr][i]=='Y' && v[i]==0)
						q.push(i);
				}
			}
		}
		return c;
	}
	void reset(vector<int>&v)
	{
		for(int i=0;i<v.size();i++)
		v[i]=0;
	}
	public:
		int countPairs(vector <string> graph)
		{
			vector<int>v(graph.size(),0);
			int cc=find(graph,v);
			int ans=0;
			for(int i=0;i<graph.size();i++)
			{
				for(int j=i+1;j<graph.size();j++)
				{
					reset(v);
					v[i]=v[j]=1;
					if(find(graph,v)>cc)
						ans++;
				}
			}
			return ans;
		}
};
int main()
{
	return 0;
}
