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
#define ll unsigned long long
#define mod 1000000007
using namespace std;

class HappyLetterDiv1
{
	public:
		string getHappyLetters(string l)
		{
			string ans="";
			
			vector<int>h1(26,0),h2(26,0);
			for(int i=0;i<l.size();i++)
				h1[l[i]-'a']++;
			
			for(int i=0;i<26;i++)
			{
				if(h1[i])
				{
					for(int j=0;j<26;j++)
					{
						if(i==j)
							h2[j]=h1[j]-1;
						else h2[j]=h1[j];
					}
			
					int mini,maxi,miniI,maxiI;
					
					while(true)
					{
						mini=INT_MAX;
						maxi=0;
						for(int j=0;j<26;j++)
						{
							if(h2[j]>maxi)
							{
								maxi=h2[j];
								maxiI=j;
							}
						}
						for(int j=0;j<26;j++)
						{
							if(h2[j]<mini && h2[j]!=0 && j!=maxiI)
							{
								mini=h2[j];
								miniI=j;
							}
						}
					
						if(mini==INT_MAX)
						{
							if(maxi!=0 && maxiI==i)
								ans.push_back('a'+i);
							else if(maxi==0)
								ans.push_back('a'+i);
							break;
						}
						h2[miniI]=0;
						h2[maxiI]-=mini;
					}
				}
			}
			return ans;
		}
};

int main()
{
	HappyLetterDiv1 obj;
	cout<<obj.getHappyLetters("ddabccadb");
	return 0;
}
