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

class ShoppingSurveyDiv1
{
	public:
		int minValue(int N, int K, vector <int> s){
			
			vector<int>v(N,0);
			if(N<s.size())
			{
				for(int i=0;i<N;i++)
				{
					for(int j=0;j<s.size();j++)
					{
						if(s[j]>0)
						{
							v[i]++;
							s[j]--;
						}
					}
				}
			
			}
			else{
			
			int i,j;
			j=0;
			for(i=0;i<s.size();i++)
			{
				while(s[i])
				{
					v[j]++;
					s[i]--;
					j=(j+1)%N;
				}
			}}
			int c=0;
			for(int i =0;i<v.size();i++)
			{
				if(v[i]>=K)
					c++;
			
			}
			return c;
		}
};

