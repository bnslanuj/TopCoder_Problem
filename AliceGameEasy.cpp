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

class AliceGameEasy
{
	public:
		long long findMinimumValue(long long x, long long y)
		{
			ll i,maxi=2000000;
			for(i=0;i<=maxi;i++)
			if(i*(i+1)==2*(x+y))break;
			if(i==maxi+1)return -1;
			int c=0;
			while(x)
			{
				if(i<=x)
				{
					x-=i;
					c++;
				}
				i--;
			}
			return c;
		}
};
int main()
{
}
