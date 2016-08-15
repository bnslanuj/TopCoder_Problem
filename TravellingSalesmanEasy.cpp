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

class TravellingSalesmanEasy
{
	public:
		int getMaxProfit(int M, vector <int> profit, vector <int> city, vector <int> visit)
		{
			int ans=0;
			for(int i=0;i<visit.size();i++)
			{
				int maxi=0,ind;
				for(int j=0;j<profit.size();j++)
				{
					if(visit[i]==city[j] && maxi<profit[j])
					{
						maxi=profit[j];
						ind=j;
					}
				}
				if(maxi>0)
				{
					ans+=maxi;
					profit[ind]*=-1;
				}
			}
			return ans;
		}
};
int main()
{
	
}
