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

class IncrementingSequence
{
	public:

	string canItBeDone(int k, vector <int> A) {
	    sort(A.begin(), A.end());
	    for(int i = 0; i < A.size() ; ++i){
            if(i+1 != A[i]){
                for(int j = i ; A[j] <= i+1 && j < A.size() ; ++j ){
                    if(( i+1 - A[j])%k == 0){
                        A[j] = A[i];
                        A[i] = i+1;
                        sort(A.begin() + i + 1 , A.end());
                        break;
                    }
                }
                if(A[i] != i+1)
                    return "IMPOSSIBLE";
            }
	    }
		return "POSSIBLE";
	}
};
int main()
{
	double in;
	
	cin>>in;
	cout<<in;
	return 0;
}
