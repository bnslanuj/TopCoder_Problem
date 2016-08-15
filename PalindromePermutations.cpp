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
ll calc(vector<ll>&num,vector<ll>&den)
{
	for(int i=2;i<=50;i++)
	{
		while(den[i])
		{
			for(int j=0;j<num.size() && den[i];j++)
			{
				while(num[j]%i==0 && den[i])
				{
					num[j]/=i;
					den[i]--;
					//break;
				}
			}
		}
	}
	ll ans=1;
	for(int i=0;i<num.size();i++)
		ans*=num[i];
	
	return ans;
}

class PalindromePermutations
{
	public:
	double palindromeProbability(string word)	
	{
		vector<ll>v;
		for(int i=1;i<=word.size();i++)
			v.push_back(i);
		
		vector<ll>hash(26,0);
		
		for(int i=0;i<word.size();i++)
			hash[word[i]-'a']++;
		
		vector<ll>temp(51,0);
		
		for(int i=0;i<26;i++)
		{
			int val=hash[i];
			while(val)
			{
				temp[val]++;
				val--;
			}
		}
		
		ll anaPerm = calc(v,temp);
		
		int odd=0;
		
		for(int i=0;i<26;i++)
		{
			if(hash[i]%2!=0)
				odd++;
			hash[i]/=2;
		}
		
		vector<ll>tem(51,0);
		
		for(int i=0;i<26;i++)
		{
			int val=hash[i];
			while(val)
			{
				tem[val]++;
				val--;
			}
		}
		
		if(odd==0 || (odd==1 && word.size()%2!=0))
		{
			v.clear();
			for(int i=1;i<=word.size()/2;i++)
				v.push_back(i);
			
			ll palPerm = calc(v,tem);
			
			return ((double)palPerm)/((double)anaPerm);
		}
		
		return 0.0;
	}	
};
