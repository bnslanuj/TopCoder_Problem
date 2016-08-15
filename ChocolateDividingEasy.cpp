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

class ChocolateDividingEasy
{
	public:
		int findBest(vector <string> cb)
		{
			int n,m;
			n=cb.size();
			m=cb[0].size();
			vector<vector<int> >ca(n+1,vector<int>(m+1,0));
			for(int i=1;i<=n;i++)
			{
				int sum=0;
				for(int j=1;j<=m;j++)
				{
					sum+=(cb[i-1][j-1]-'0');
					ca[i][j]+=sum+ca[i-1][j];
				}
			}
			int ans=0;
			for(int i=1;i<n;i++)
			for(int j=1;j<m;j++)
			for(int dx=0;dx<=n-3 && i+dx<n-1;dx++)
			for(int dy=0;dy<=m-3 && j+dy<m-1;dy++)
			{
				int x,y,t;
				x=i+dx;
				y=j+dy;
				t=INT_MAX;
				t=min(t,ca[i][j]);
				t=min(t,ca[i][y+1]-ca[i][j]);
				t=min(t,ca[i][m]-ca[i][y+1]);
				t=min(t,ca[x+1][j]-ca[i][j]);
				t=min(t,ca[x+1][y+1]+ca[i][j]-ca[x+1][j]-ca[i][y+1]);
				t=min(t,ca[x+1][m]-ca[x+1][y+1]-ca[i][m]+ca[i][y+1]);
				t=min(t,ca[n][j]-ca[x+1][j]);
				t=min(t,ca[n][y+1]-ca[x+1][y+1]-ca[n][j]+ca[x+1][j]);
				t=min(t,ca[n][m]-ca[x+1][m]-ca[n][y+1]+ca[x+1][y+1]);
				ans=max(t,ans);
			}
			return ans;
		}
};
int main()
{
	char a,b;
	a='9';
	b='9';
	char c=a+b;
	printf("%c",c);
	vector<string>v(3);
	v[0]="9768";
	v[1]="6767";
	v[2]="5313";
	ChocolateDividingEasy obj;
	cout<<obj.findBest(v);
}
