#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define PI 3.14159265358979323846
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
void solve()
{
    ll n;
    cin>>n;
    vector<ll> v(n);
    scan_vector(v);
    vector<ll> a(n,0);
    ll r=-1;
    for(ll i=n-1;i>=0;i--)
    {
        if(v[i]!=0)
        {
            r=i;
            break;
        }
    }
    if(r==-1)
    YES;
    else if(r==0)
    {
        if(v[0]==0)
        YES;
        else NO;
    }
    else
    {
        if(v[0]==0)
        {
            NO;
            return;
        }
        for(ll i=1;i<=r;i++)
        {
            v[i]++;
        }
        for(ll i=0;i<r;i++)
        {
            if(v[i]-a[i]<=0)
            {
                NO;
                return;
            }
            else
            {
                ll d=v[i]-a[i];
                a[i]+=d;
                a[i+1]-=(d-1);
            }
        }
        // print_vector(v);
        // print_vector(a);
        if(v==a)
        YES;
        else
        NO;
    }

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