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

class QuadraticLaw{
	public:
		long long getTime(long long d)
		{
			ll low,mid,high,ans;
			low=0;
			high=(ll)sqrt(d);
			
			while(low<=high)
			{
				mid=low+(high-low)/2;
				ll val=d-mid*mid-mid;
				
				if(val>=0)
				{
					ans=mid;
					low=mid+1;
				}
				else 
					high=mid-1;
					
			}
			return ans;
		}
};
int main()
{
	return 0;
}
