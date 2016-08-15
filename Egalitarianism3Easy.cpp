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
int countB(int i)
{
	int c=0;
	while(i)
	{
		if(i&1)c++;
		i>>=1;
	}
	return c;
}
class Egalitarianism3Easy
{
	public:
		int maxCities(int n, vector <int> a, vector <int> b, vector <int> len){
			vector<vector<int> >arr(n,vector<int>(n,mod));
			
			for(int i=0;i<a.size();i++)
				arr[a[i]-1][b[i]-1]=arr[b[i]-1][a[i]-1]=len[i];
			
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					for(int k=0;k<n;k++)
						if(arr[j][i]!=mod && arr[i][k]!=mod)
							arr[j][k]=min(arr[j][k],arr[j][i]+arr[i][k]);
			
	
			int ans=1;
		
			for(int i=0;i<(1<<(n));i++)
			{
				int dis=0;bool done=1;
				for(int j=0;j<n;j++)
				{
					for(int k=0;k<n;k++)
					{
						if(j!=k && ((1<<j)&i) && ((1<<k)&i))
						{
							if(dis==0)dis=arr[j][k];
							else if(dis!=arr[j][k])
							{
								done=0;break;
							}
						}
					}
					if(done==0)break;
				}
				if(done)
					ans=max(ans,countB(i));
			}
			return ans;
		}
};
int main()
{
	cout<<(1<<2)<<endl;
	vector<int>a(3),b(3),c(3);
	a[0]=a[1]=a[2]=1;
	b[0]=2;b[1]=3;b[2]=4;
	c[0]=c[1]=c[2]=1;
	Egalitarianism3Easy obj;
	cout<<obj.maxCities(4,a,b,c);
	
	return 0;
}
