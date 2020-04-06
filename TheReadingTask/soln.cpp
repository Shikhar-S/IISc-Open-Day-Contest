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
vector<string> v;
int freq[100005][26];
string reference;
int n,m;
bool match(int i,int rolling_freq[],int at)
{
	//match first and last characters
	if(v[i][0]!=reference[at] || v[i][v[i].size()-1]!=reference[at+v[i].size()-1])
		return false;

	for(int k=0;k<26;k++)
	{
		if(rolling_freq[k]!=freq[i][k])
			return false;
	}
	return true;
}
int main()
{
	memset(freq,0,sizeof(freq));
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	string x;cin>>x;v.pb(x);
    	for(int j=0;j<x.size();j++)
    	{
    		freq[i][x[j]-'a']++;
    	}
    }
    cin>>m;
    cin>>reference;
    int ans=0;
    for(int i=0;i<n;i++)
    {
    	int n_v=v[i].size();
    	int rolling_freq[26];
    	memset(rolling_freq,0,sizeof(rolling_freq));
    	for(int j=0;j<n_v;j++)
    		rolling_freq[reference[j]-'a']++;
    	if(match(i,rolling_freq,0))
    	{
    		ans++;
    		continue;
    	}
    	for(int j=n_v;j<reference.size();j++)
    	{
    		rolling_freq[reference[j-n_v]-'a']--;
    		rolling_freq[reference[j]-'a']++;
    		if(match(i,rolling_freq,j-n_v+1))
    		{
    			ans++;
    			break;
    		}
    	}
    }
    cout<<ans<<endl;
    return 0;
}