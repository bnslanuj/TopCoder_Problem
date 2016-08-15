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

class SortishDiv2
{
	int ans=0;
	int SN;
	int countSN(vector<int>&v)
	{
		int add=0;
		for(int i=0;i<v.size();i++)
		for(int j=i+1;j<v.size();j++)
		if(v[j]>v[i])
			add++;
		return add;	
	}
	void fun(vector<int>&seq,vector<int>&ele,int curr)
	{
		if(curr==ele.size() && countSN(seq)==SN)
		{
			ans++;
			return ;
		}
		for(int i=0;i<seq.size();i++)
		{
			if(seq[i]==0)
			{
				seq[i]=ele[curr];
				fun(seq,ele,curr+1);
				seq[i]=0;
			}
		}
	}
	public:
		int ways(int sn, vector <int> seq)
		{
			SN=sn;
			vector<int>hash(seq.size(),0);
			for(int i=0;i<seq.size();i++)
			if(seq[i])
				hash[seq[i]-1]=1;
			vector<int>ele;
			for(int i=0;i<seq.size();i++)
			if(!hash[i])
				ele.push_back(i+1);
			fun(seq,ele,0);
			return ans;
		}
};
int main()
{
	SortishDiv2 obj;
	vector<int>v(5,0);
	v[0]=4;
	v[1]=v[2]=v[4]=0;
	v[3]=2;
	
	cout<<obj.ways(5,v)<<endl;
	return 0;
}
