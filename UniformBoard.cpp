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
double pi=2*acos(0.0);
using namespace std;
class UniformBoard
{
	public:
	int getBoard(vector <string> board, int K)
	{
		int i,j,x,y,n=board.size();
		
		vector<vector<int> >ac(n,vector<int>(n,0));
		vector<vector<int> >pc(n,vector<int>(n,0));
		
		for(i=0;i<n;i++)
		{
			int app,pear;
			app=pear=0;
			
			for(j=0;j<n;j++)
			{
				if(board[i][j]=='A')
					app++;
				else if(board[i][j]=='P')
					pear++;
				if(i-1>=0)
				{
					pc[i][j]=pear+pc[i-1][j];
					ac[i][j]=app+ac[i-1][j];
				}
				else 
				{
					ac[i][j]=app;
					pc[i][j]=pear;
				}
			}
		}
		bool isDot=n*n-(ac[n-1][n-1]+pc[n-1][n-1])==0?0:1;
		int ans=0;
		for(x=0;x<n;x++)
		{
			for(y=0;y<n;y++)
			{
				for(i=x;i<n;i++)
				{
					for(j=y;j<n;j++)
					{
						int inApp=0;
						int inPear=0;
						inApp=ac[i][j];
						inPear=pc[i][j];
						if(x-1>=0)
						{
							inPear-=pc[x-1][j];
							inApp-=ac[x-1][j];
						}
						if(y-1>=0)
						{
							inPear-=pc[i][y-1];
							inApp-=ac[i][y-1];
						}
						if(x-1>=0&&y-1>=0)
						{
							inPear+=pc[x-1][y-1];
							inApp+=ac[x-1][y-1];
						}
						int size=(i-x+1)*(j-y+1);
						int outApp=ac[n-1][n-1]-inApp;
					
						
						if(isDot)
						{
							int req=size-inApp;
							req+=inPear;
							if(req<=K && size-inApp<=outApp)
								ans=max(ans,size);
						}
						else if(size==inApp)
							ans=max(ans,size);
					}
				}
			}
		}
		return ans;
	}	
};
int main()
{
	vector<string>v(2);
	v[0]="AP";
	v[1]=".A";
	UniformBoard obj;
	cout<<obj.getBoard(v,2);
	return 0;
}
