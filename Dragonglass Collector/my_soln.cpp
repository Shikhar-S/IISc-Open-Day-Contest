
// Sample code to perform I/O:

#include <iostream>
#include <cstring>
#include <limits>
#define imin numeric_limits<int>::min()
typedef long long ll;
using namespace std;
ll len[1003];
ll q[1003];
int dp[1003][102][102];
ll max(ll a,ll b,ll c,ll d)
{
    return max(a,max(b,max(c,d)));
}
ll f(int n,int l1,int l2)
{
    
    
    if(l1<0 || l2<0)
    return imin;
    
    if(n<0)
    return 0;
    
    if(dp[n][l1][l2]!=-1)
    return dp[n][l1][l2];

    return dp[n][l1][l2]=max(f(n-1,l1,l2),
                            f(n-1,l1-len[n],l2)+q[n],
                            f(n-1,l1,l2-len[n])+q[n],
                            ((len[n]==2)?q[n]+f(n-1,l1-1,l2-1):imin));
}
int main() {
	ll n,L;
	cin>>n>>L;
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;i++)
	{
	    cin>>len[i]>>q[i];
	}
	cout<<f(n-1,L,L)<<endl;
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail


// Write your code here
