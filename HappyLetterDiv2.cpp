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

class HappyLetterDiv2
{
	public:
		char getHappyLetter(string l)
		{
			int c=0;
			char ch;
			
			for(int i=0;i<l.size();i++)
			{
				if(c==0)
				{
					c=1;
					ch=l[i];
				}
				else if(ch==l[i])
					c++;
				else c--;
			}
			
			c=0;
			for(int i=0;i<l.size();i++)
			{
				if(ch==l[i])
					c++;
			}
			if(c>l.size()/2)
				return ch;
			return '.';
		}
};
