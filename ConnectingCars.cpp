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

class ConnectingCars
{
	public:
		long long minimizeCost(vector <int> positions, vector <int> lengths)
		{
			vector<pair<int,int> >v;
			for(int i=0;i<positions.size();i++)
				v.push_back(make_pair(positions[i],lengths[i]));
			
			sort(v.begin(),v.end());
			ll ans=LLONG_MAX;
			for(int i=0;i<positions.size();i++)
			{
				ll l=v[i].first;
				ll c=0;
				for(int j=i-1;j>=0;j--)
				{
					c+=l-(v[j].first+v[j].second);
					l-=v[j].second;
				}
				l=v[i].first+v[i].second;
				for(int j=i+1;j<positions.size();j++)
				{
					c+=v[j].first-l;
					l+=v[j].second;
				}
				ans=min(ans,c);
			}
			return ans;
		}
};
int main()
{
}
