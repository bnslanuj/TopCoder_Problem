#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<queue>
#include<map>
#include<stack>
#include<set>
#include<vector>
#include<ctime>
#include<string>
#include<algorithm>
#include<cmath>
#define ll long long
#define mod 1000000007
using namespace std;

class NumbersChallenge{
	public:
	int MinNumber(vector <int> S)
	{
		set<int>s,t;
		set<int>::iterator it;
		for(int i=0;i<S.size();i++)
		{
			for(it=s.begin();it!=s.end();it++)
			{
				if(s.find(*it+S[i])==s.end())
					t.insert(*it+S[i]);
			}
			if(s.find(S[i])==s.end())
				t.insert(S[i]);
			
			for(it=t.begin();it!=t.end();it++)
				s.insert(*it);
			
			t.clear();
		}
		for(int i=1;;i++)
		{
			if(s.find(i)==s.end())
				return i;
		}
		return 0;
	}
};
