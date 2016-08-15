#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<queue>
#include<map>
#include<stack>
#include<set>
#include<vector>
#include<ctime>
#include<string>
#include<algorithm>
#include<cmath>
#define ll long long
#define mod 1000000007
double pi=2*acos(0.0);
using namespace std;

class BuildingHeightsEasy
{
	public:
		int minimum(int M, vector <int> h)
		{
			sort(h.begin(),h.end());
			int ans=INT_MAX;
			for(int j=h.size()-1;j>=0;j--)
			{
				int k=M;
	
				int curr=0;
				for(int i=j; i>=0 && k;i--,k--)
					curr+=(h[j]-h[i]);
				
				if(k==0)
					ans=min(ans,curr);
			}
			return ans;
		}
};
