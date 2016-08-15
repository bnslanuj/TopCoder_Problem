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
const int offset=1001;
vector<vector<bool> >isBlocked(2009,vector<bool>(2009,0));
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

class TheGridDivTwo
{
	
	public:
		int find(vector <int> x, vector <int> y, int k)
		{
			for(int i=0;i<x.size();i++)
				isBlocked[x[i]+offset][y[i]+offset]=1;
			
			int maxi=0;
			queue<int>X,Y,S;
			X.push(offset);
			Y.push(offset);
			S.push(0);
			isBlocked[offset][offset]=1;
			
			while(!X.empty())
			{
				int currx=X.front();
				int curry=Y.front();
				int currs=S.front();
				X.pop();Y.pop();S.pop();
				maxi=max(maxi,currx);
				for(int i=0;i<4;i++)
				{
					if(isBlocked[currx+dx[i]][curry+dy[i]]==0 && currs+1<=k)
					{
						isBlocked[currx+dx[i]][curry+dy[i]]=1;
						X.push(currx+dx[i]);
						Y.push(curry+dy[i]);
						S.push(currs+1);
					}
				}
			}
			return maxi-offset;
		}
};
int main()
{
	vector<int>x,y;
	
	TheGridDivTwo obj;
	cout<<obj.find(x,y,1000);
}

