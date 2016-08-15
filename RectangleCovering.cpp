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
void swap(int &a,int &b)
{
	int t=a;
	a=b;
	b=t;
}
class RectangleCovering
{
	public:
		int minimumNumber(int hH, int hW, vector <int> bH, vector <int> bW)
		{
			if(hW<hH)
				swap(hW,hH);
			for(int i=0;i<bH.size();i++)
			{
				if(bW[i]<bH[i])
					swap(bW[i],bH[i]);
			}
			//special case
			if(bH.size()==1)
			{
				if(hW==bW[0] && bH[0]>hH)
					return 1;
			}
			int tH=hH,tW=hW;
			//try all horizontal..
			int ans=100;
			int count=0;
			bool isDone=0;
			vector<bool>v(bH.size(),0);
			for(int i=0;i<bH.size();i++)
			{
				int ind=-1,max=0;
				for(int j=0;j<bH.size();j++)
				{
					if(v[j]==0 && bW[j]>hW && max<bH[j])
					{
						max=bH[j];
						ind=j;
					}
				}
				if(ind==-1)break;
				v[ind]=1;
				hH-=bH[ind];
				count++;
				if(hH<=0)
				{
					isDone=1;break;
				}
			}
			if(isDone)
				ans=min(ans,count);
			
			//try all vertical..
			hH=tH;
			hW=tW;
			fill(v.begin(),v.end(),0);
			isDone=0;
			count=0;
			for(int i=0;i<bH.size();i++)
			{
				int ind=-1,max=0;
				for(int j=0;j<bH.size();j++)
				{
					if(v[j]==0 && bW[j]>hH && max<bH[j])
					{
						max=bH[j];
						ind=j;
					}
					if(v[j]==0 && bH[j]>hH && max<bW[j])
					{
						max=bW[j];
						ind=j;
					}
				}
				if(ind==-1)break;
				v[ind]=1;
				hW-=max;
				count++;
				if(hW<=0)
				{
					isDone=1;break;
				}
			}
			if(isDone)
				ans=min(ans,count);
			if(ans==100)return -1;
			return ans;
		}
};
int main()
{
	
}
