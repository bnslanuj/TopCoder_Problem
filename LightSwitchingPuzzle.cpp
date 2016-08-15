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

class LightSwitchingPuzzle
{
	public:
		int minFlips(string s)
		{
			int c=0;
			for(int i=1;i<=s.size();i++)
			{
				if(s[i-1]=='Y')
				{
					c++;
					s[i-1]='N';
					for(int j=i+i;j<=s.size();j+=i)
					{
						if(s[j-1]=='Y')
							s[j-1]='N';
						else s[j-1]='Y';
					}
				}
			}
			return c;
		}
};
