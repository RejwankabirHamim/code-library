#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using    namespace __gnu_pbds;
using    namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M  1000000007  //998244353 //
#define ll long long
#define pa pair<ll,ll>
#define ff first
#define ss second
#define pb push_back
#define pi acos(-1.0)
#define vi vector<int>
#define vll vector<ll>
#define fr(i,n,j) for(i=j;i<=n;i++)
#define rfr(i,n,j) for(i=n;i>=j;i--)
#define ct continue;
#define yo cout<<"Yes"<<endl
#define no cout<<"No"<<endl
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define all(v) v.begin(),v.end()
ll a[500005],b[500005],c[500005],dp[500005];
#define endl '\n'
long long int mod_inverse(long long int x,long long int p)//x is fact[i] and p is M-2
{
    long long int res=1,y=p;
    while(y>0)
    {
        if(y&1) res=((res%M)*(x%M))%M;
        y=y>>1;
        x=((x%M)*(x%M))%M;
    }
    return res;
}
ll ncr(ll n,ll r)//here b is for fact
{
    if(n<r||n<0||r<0)return 0;
    ll ans=b[n];
    ans=(ans*c[r])%M;
    ans=(ans*c[n-r])%M;
    return ans;
}
int main()
{
    fast;
    ll te,n,m,i,j,k,w,x,y,z,l2,r2,k2,k1,q,l,r;
    b[0]=1;
    fr(i,200000,1)b[i]=(b[i-1]*i)%M;
    c[200000]=mod_inverse(b[100],M-2);
    rfr(i,200000-1,0)c[i]=(c[i+1]*(i+1))%M;

}
