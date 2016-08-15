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

class LostCharacter
{
	void fix(string &str,char c)
	{
		for(int i=0;i<str.size();i++)
		if(str[i]=='?')str[i]=c;
		return ;
	}
	public:
		vector <int> getmins(vector <string> str)
		{
			vector<int>ans;
			for(int i=0;i<str.size();i++)
			{
				string temp=str[i];
				fix(temp,'a');
				int c=0;
				for(int j=0;j<str.size();j++)
				{
					if(i==j)continue;
					string temp1=str[j];
					fix(temp1,'z');
					if(temp1<temp)c++;
				}
				ans.push_back(c);
			}
			return ans;
		}
};
int main()
{
}
