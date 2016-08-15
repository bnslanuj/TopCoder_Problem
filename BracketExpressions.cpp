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

class BracketExpressions
{
	public:
		string ifPossible(string e)
		{
			if(e.size()&1)return "impossible";
			int c=0;
			for(int i=0;i<e.size();i++)
			{
				if(e[i]=='X')
					c++;	
			}
			
			c=1<<(c+1);
			for(int k=0;k<c;k++)
			{
				int xc=0;
				stack<char>s;
				int done=1;
			
				for(int i=0;i<e.size();i++)
				{
					
					if(e[i]=='('||e[i]=='{'||e[i]=='[')
						s.push(e[i]);
					else if(e[i]=='X')
					{
						xc++;
						if((1<<xc)&k)
							s.push('X');
						else if(s.empty())
						{
							done=0;
							break;
						}
						else
							s.pop();
					}
					else if(e[i]==')' && !s.empty() && (s.top()=='('||s.top()=='X'))
						s.pop();
					else if(e[i]=='}' && !s.empty() && (s.top()=='{'||s.top()=='X'))
						s.pop();
					else if(e[i]==']' && !s.empty() && (s.top()=='['||s.top()=='X'))
						s.pop();
					else 
					{
						done=0;
						break;
					}
				}
				if(done && s.empty())
					return "possible";
			}
		
			return "impossible";
		}
};
int main()
{
	BracketExpressions obj;
	cout<<obj.ifPossible("([]X()[()]XX}[])X{{}}]");
	return 0;
}
