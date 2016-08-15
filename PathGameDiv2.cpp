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

class PathGameDiv2
{
	public:
		int calc(vector <string> b)
		{
			int l=b[0].size();
			vector<vector<int> >v(2,vector<int>(l,mod));
			int w=0;
			if(b[0][0]=='.')
			{
				w++;
				v[0][0]=1;
			}
			if(b[1][0]=='.')
			{
				w++;
				v[1][0]=1;
			}
			for(int i=1;i<l;i++)
			{
				int a=mod;
				if(b[0][i-1]=='.')
					a=min(a,v[0][i-1]+1);
				if(v[1][i-1]!=mod && b[1][i]=='.')
					a=min(a,v[1][i-1]+2);
				if(b[0][i]=='.')
				{
					w++;
					v[0][i]=a;
				}
				a=mod;
				a=min(a,v[0][i]+1);
				if(b[1][i-1]=='.')
					a=min(a,v[1][i-1]+1);
				if(b[1][i]=='.')
				{
					w++;
					v[1][i]=a;
				}
			}
			return w-min(v[0][l-1],v[1][l-1]);
		}
};
int main()
{
	return 0;
}

