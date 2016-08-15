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
#define ll unsigned long long
#define mod 1000000007
using namespace std;

class FixedDiceGameDiv2
{
	public:
		double getExpectation(int a, int b)
		{
			int c=0;
			int val=0;
			
			while(a)
			{
				c+=a*min(b,a-1);
				val+=min(b,a-1);
				a--;
			}
			return (double)c/(double)/val;
		}
};
