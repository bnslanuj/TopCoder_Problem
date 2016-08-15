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

class CatAndRat
{
	public:
		double getTime(int R, int T, int Vrat, int Vcat)
		{
			if(Vrat>=Vcat)return -1.0;
			double val;
			if((double)(Vrat*T)>=pi*R)
				val=pi*R;
			else
				val=(double)(Vrat*T);
			return (val)/((double)(Vcat-Vrat));
		}
};

