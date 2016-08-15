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

class BuildingHeights
{
	public:
		int minimum(vector <int> h)
		{
			sort(h.begin(),h.end());
			
			int i,j,n=h.size();
			int ans=-1;
			for(i=n;i>=1;i--)
			{
				queue<int>q;
				int sum=0;
				for(j=0;j<i;j++)
				{
					sum+=h[j];
					q.push(h[j]);
				}
				
				int val=i*h[j-1]-sum;
				
				while(j<n)
				{
					sum-=q.front();
					q.pop();
					sum+=h[j];
					q.push(h[j]);
					
					val=min(val,i*h[j]-sum);
					j++;
				}
				if(val==0)break;
				
				if(ans==-1)
					ans=val;
				else ans^=val;
			}
			if(ans==-1)return 0;
			return ans;
		}
};
