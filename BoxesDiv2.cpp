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

int giveNum(int n)
{
	if((n&(n-1))==0)return n;
	int temp=1;
	while(temp<n)
		temp<<=1;
	return temp;
}

class BoxesDiv2
{
	public:
		int findSize(vector <int> v)
		{
			priority_queue<int>pq;
			
			for(int i=0;i<v.size();i++)
			{
				pq.push(-1*giveNum(v[i]));
			}

			while(pq.size()!=1)
			{
				int num=pq.top();
				pq.pop();
				num+=pq.top();
				pq.pop();
				num*=-1;
			
				pq.push(-1*giveNum(num));
			}
	
			return -1*pq.top();
		}
};
int main()
{
	BoxesDiv2 obj;
	vector<int>v(5);
	v[0]=v[1]=1;
	v[2]=13;v[3]=v[4]=1;
	
	cout<<obj.findSize(v);
	return 0;
}
