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

class ShoppingSurveyDiv2
{
	public:
		int minValue(int N, vector <int> s)
		{
			int sum=0;
			for(int i=0;i<s.size();i++)
				sum+=s[i];
			if(sum==N*s.size())return N;
			if(sum/N>=s.size()-1)
				return sum%N;
			return 0;
		}
};
int main()
{
	
	return 0;
}
