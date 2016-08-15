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

class NumberGameAgain
{
	public:
		long long solve(int k, vector<long long> table)
		{
			sort(table.begin(),table.end());
			for(int i=1;i<table.size();i++)
			{
				ll temp=table[i];
				while(temp)
				{
					for(int j=0;j<i;j++)
					{
						if(temp==table[j])
						{
							table[i]*=-1;
							break;
						}
					}
					if(table[i]<0)break;
					temp>>=1;
				}
			}
	
			ll c=0;
			for(int i=0;i<table.size();i++)
			{
				ll l=0;
				while(table[i]>0)
				{
					l++;
					table[i]>>=1;
				}
				if(l)
					c+=(1LL<<(k-l+1))-1;
			
			}
			//cout<<k<<endl;
			return (1LL<<k)-c-2;
		}
};

int main()
{
	vector<ll>v;
	ll num=(ll)(1LL<<40);num--;
cout<<num<<endl;
	NumberGameAgain obj;
	cout<<obj.solve(40,v);
	return 0;
}
