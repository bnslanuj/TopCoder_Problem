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
ll fact[55];
ll invfact[55];

ll raise(ll a,ll b)
{
	if(b==0)
		return 1;
	if(b==1)
		return a;
	ll val=raise(a,b/2);
	val=(val*val)%mod;
	if(b&1)
		return (val*a)%mod;
	return val;
}

void init()
{
	invfact[0]=invfact[1]=fact[0]=fact[1]=1;
	for(ll i=2;i<=50;i++)
		fact[i]=(fact[i-1]*i)%mod;
	
	for(ll i=2;i<=50;i++)
		invfact[i]=raise(fact[i],mod-2);
}

ll ncr(ll n,ll r)
{
	return (((fact[n]*invfact[r])%mod)*invfact[n-r])%mod;
}
class OkonomiyakiParty
{
	public:
		int count(vector <int> s, int M, int K)
		{
			init();
			sort(s.begin(),s.end());
			int i,j;
			i=0;j=0;
			ll ans=0;
			while(j<s.size())
			{
				if(s[j]-s[i]<=K)
					j++;
				else
				{
					if(j-i>=M)
						ans+=ncr(j-i-1,M-1);
						ans%=mod;
					i++;
					j--;
				}
			}
			while(j-i>=M)
			{
				ans+=ncr(j-i-1,M-1);
				ans%=mod;
				i++;
			}
			return ans;
		}
};

int main()
{
}
