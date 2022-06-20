#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
typedef unsigned long long ull;

ll nCr(ll n,ll r)
{
    if(r>n)
    return 0;
    if(r==n || r==0)
    return 1;
    else
    {
        ll k=1;
        for(ll i=r+1;i<=n;i++)
        k=k*i;
        for(ll i=1;i<=(n-r);i++)
        k/=i;
        return k;
    }
}
ll binarySearch(vector<ll> &v,ll n,ll k)
{
    ll lb=0;
    ll ub=n-1;
    while(ub-lb>1)
    {
        ll mid=lb+(ub-lb)/2;
        if(v[mid]>k)
        {
            ub=mid-1;
        }
        else
        {
            lb=mid;
        }
    }
    if(v[lb]==k)
    return lb;
    else if(v[ub]==k)
    return ub;
    else
    return -1;
}
ull power(ull x,ll y,ll p)
{
    ull res=1;
    x=x%MOD;
    while(y>0)
    {
        if(y&1)
        {
            res=(res*x)%MOD;
        }
    y=y>>1;
    x=(x*x)%p;
    }
    return res;
}
ull modInverse(ull n,ll p)
{
    return power(n,p-2,p);
}
ull nCrFermat(ull n,ll r,ll p)
{
    if(n<r)
    return 0;
    if(r==0)
    return 1;
    ull fac[n+1];
    fac[0]=1;
    for(ll i=1;i<=n;i++)
    fac[i]=(i*fac[i-1])%p;
    return(fac[n]*modInverse(fac[r],p)%p*modInverse(fac[n-r],p)%p)%p;
}
ll binExp(ll x,ll y)
{
    if(y==0)
    return 1;
    else if(y%2==1)
    {
        return x*binExp(x,y/2)*binExp(x,y/2);
    }
    else
    {
        return binExp(x,y/2)*binExp(x,y/2);
    }
}
map<ll,ll> primeFactorization(ll n)
{
    map<ll,ll> m;
    while(n%2==0)
    {
        m[2]++;
        n/=2;
    }
    for(ll i=3;i*i<=n;i+=2)
    {
        while(n%i==0)
        {
            m[i]++;
            n/=i;
        }
    }
    if(n>2)
    m[n]++;
    return m;
}
void buildSegTree(vector<ll> &v,vector<ll> &seg,ll n,ll l,ll r)
{
    //sizeof(seg) = 4*sizeof(v)
    if(l==r)
    {
        seg[n]=v[l];
        return;
    }
    ll mid=(l+r)/2;
    buildSegTree(v,seg,2*n+1,l,mid);
    buildSegTree(v,seg,2*n+2,mid+1,r);
    seg[n]=seg[2*n+1]+seg[2*n+2];
}
ll query(vector<ll> &seg,ll n,ll low,ll high,ll l, ll r)
{
    //low,high -seg tree ranges
    //l,r - requested ranges
    //n = 0 for root
    //Requested Range must engulf node range
    if(low>=l && high<=r)
    return seg[n];
    else if(high<l || low>r)
    return 0;
    int mid=(low+high)/2;
    return query(seg,2*n+1,low,mid,l,r)+query(seg,2*n+2,mid+1,high,l,r);
}