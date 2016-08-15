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
//{999999999998, 2}
//{2000001, 999997999999}
class AliceGame
{
	public:
		long long findMinimumValue(long long x, long long y)
		{
			ll i,maxi=2000000;
			for(i=0;i<=maxi;i++)
			if(i*i==(x+y))break;
			cout<<i<<endl;
			if(i==maxi+1)return -1;
			int c=0;
			while(x)
			{
				if(2*i-1<=x && x-2*i+1!=2)
				{
					x-=2*i-1;
					c++;
				}
				i--;
				if(i==-1)break;
			}
			if(x)return -1;
			return c;
		}
};
int main()
{
	AliceGame obj;
	cout<<obj.findMinimumValue(2000001,999997999999);
}
