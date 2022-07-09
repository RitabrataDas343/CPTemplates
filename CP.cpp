#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(ll i=0;i<n;i++)
#define FOR(i,l,r) for(ll i=l;i<r;i++)
#define Endl cout<<"\n";
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define scan_vector(v)      for (auto &it: v) { cin>>it; }
#define print_vector(v)     for (auto &it: v) { cout<<it<<" "; } cout<<endl;
#define print_map(m)     for (auto &it: m) { cout<<it.first<<"->"<<it.second<<"\n"; } 
#define deb(x) cout<<#x<<"="<<x<<endl;
#define all(x) x.begin(),x.end()
typedef long long ll;
typedef unsigned long long ull;
const ll MOD=(1e9+7);
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
ll mod(ll n)
{
    return ((n%MOD+MOD)%MOD);
}
int fun(string &s,int i,int n,int M,int K,vector<vector<int>> &dp)
{
    if(i>=n)
    {
        if(K==0)
        return 1;
        return 0;
    }
    // string t="";
    if(dp[i][K]!=-1)
    return dp[i][K];
    char a=s[i];
    long long ans=0;
    for(int j=i+M-1;j<n;j++)
    {
        // t.push_back(s[j]);
        char b=s[j];
        if(a%2==0 && b%2==1)
        ans=(ans%MOD+fun(s,j+1,n,M,K-1,dp)%MOD)%MOD;
    }
    return dp[i][K]=ans;
}
void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    string s;
    cin>>s;
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    cout<<fun(s,0,n,m,k,dp)<<endl;
}
int main()
{
    
    fastIO(); 
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ll t=1;
    cin>>t;
    ll T=t;
    while(t--)
    {
        // cout<<"Case #"<<T-t<<": ";
        solve();     
    }

}