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

int dp[51][51][1300];
void init()
{
	for(int i=0;i<51;i++)
	{
		for(int j=0;j<51;j++)
		{
			for(int k=0;k<1300;k++)
			dp[i][j][k]=-1;
		}
	}
}
int k;
string ans;
int fun(int curr,int ac,int pc,int n,string &str)
{
	//printf("%d %d\n",curr,n);
	if(n<=curr)
	{
		if(k==pc)
		{
			ans=str;
			return 1;
		}
		return 0;
	}
	if(dp[curr][ac][pc]!=-1)return dp[curr][ac][pc];
	
	int a=0,b=0;
	str[curr]='A';
	a=fun(curr+1,ac+1,pc,n,str);
	str[curr]='B';
	b=fun(curr+1,ac,pc+ac,n,str);
	dp[curr][ac][pc]=(a|b);
	return dp[curr][ac][pc];
}
class AB
{
	
	public:
		string createString(int N, int K)
		{
			k=K;init();
			string str(N,'\0');
			int ret=fun(0,0,0,N,str);
			if(ret)return ans;
			return "";
		}
};
int main()
{
	AB obj;
	for(int i=0;i<5;i++)
	{
		int n,k;
		cin>>n>>k;
		cout<<obj.createString(n,k);
	}
	return 0;
}
