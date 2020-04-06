#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <unordered_map>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef vector < ll > vll;
typedef pair <int, int> pii;
typedef pair<ll, ll> pll;
#define rep(i,a,n) for(i=a;i<=n;i++)
#define per(i,n,a) for(i=n;i>=a;i--)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define iOS ios_base::sync_with_stdio(false); cin.tie(NULL)
#define imax numeric_limits<int>::max()
#define imin numeric_limits<int>::min()
#define llmax numeric_limits<ll>::max()
#define llmin numeric_limits<ll>::min()
ll powmod(ll a,ll b) {ll res=1;if(a>=MOD)a%=MOD;for(;b;b>>=1){if(b&1)res=res*a;if(res>=MOD)res%=MOD;a=a*a;if(a>=MOD)a%=MOD;}return res;}
ll gcd(ll a , ll b){return b==0?a:gcd(b,a%b);}
/****************CODE STARTS HERE*******************/

int dp[1000][105][105];

int max(int a, int b, int c, int d)
{
	if(a>=b && a>=c && a>=d) return a;
	if(b>=c && b>=d) return b;
	if(c>=d) return c;
	return d;
}

int main()
{
	int n, L, i, j, k, l, v;
	int lengths[1000];
	int values[1000];
	//int lengths[4] = {3, 4, 1, 2};
	//int values[4] = {3, 2, 3, 2};
	//n=4;
	//w=5;
	//int lengths[3] = {4, 4, 4};
	//int values[3] = {5, 5, 5};
	//n=3;
	//w=6;
	
	cin>>n>>L;
	for(i=0;i<n;i++) cin>>lengths[i]>>values[i];
	for(j=0;j<=L;j++)
	for(k=0;k<=L;k++)
	{
		l = lengths[0];
		v = values[0];
		if(j>=l || k>=l) dp[0][j][k] = v;
		else dp[0][j][k] = 0;
	}
	for(i=1;i<n;i++)
	{
		for(j=0;j<=L;j++)
		for(k=0;k<=L;k++)
		{
			l = lengths[i];
			v = values[i];
			int v1 = 0;
			if(j>=l) v1 = dp[i-1][j-l][k]+v;
			int v2 = 0;
			if(k>=l) v2 = dp[i-1][j][k-l]+v;
			int v3 = 0;
			if( l==2 && j>0 && k >0) v3 = dp[i-1][j-1][k-1]+v;
			dp[i][j][k] = max(dp[i-1][j][k], v1, v2, v3);
			//cout<<"dp["<<i<<"]["<<j<<"]["<<k<<"] is max of "<<dp[i-1][j][k]<<' '<<v1<<' '<<v2<<' '<<v3;
			//cout<<" which is "<<dp[i][j][k]<<endl;
		}
	}
	
	cout<<dp[n-1][L][L]<<endl;
	/*for(i=0;i<n;i++)
	{
		for(j=0;j<=L;j++)
		{
			for(k=0;k<=L;k++)
			{
				cout<<dp[i][j][k]<<' ';
			}
			cout<<endl;
		}
		cout<<endl<<endl;
	}*/
}