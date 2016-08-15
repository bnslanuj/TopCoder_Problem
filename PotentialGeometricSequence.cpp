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

class PotentialGeometricSequence
{
	public:
		int numberOfSubsequences(vector <int> d)
		{
			int i,j;
			int ans=d.size();
			for(i=0;i<d.size()-1;)
			{
				int diff=d[i+1]-d[i];
				j=i+1;
				while(j<d.size() && d[j]-d[j-1]==diff)
					j++;
				j--;
				
				int l=j-i+1;
				ans+=(l*(l+1))/2;
				ans-=l;
				i=j;
			}
			return ans;
		}
};


