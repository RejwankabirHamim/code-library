#include<bits/stdc++.h>
using namespace std;
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000000007
#define M1 998244353
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
#define yo cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define srt(v) sort(v.begin(),v.end())
ll int a[500005],c[500005],b[500005],dp[500005],d[500005];
void next_lowest(ll int a[],ll int b[],ll int n)
{
    stack<pa>s;
    s.push({-1,n+1});
    for(int i=n;i>=1;i--)
    {
        while(s.top().ff>=a[i])s.pop();
        b[i]=s.top().ss;
        s.push({a[i],i});
    }
}
void next_highest(ll int a[],ll int c[],ll int n)
{
    stack<pa>s;
    s.push({n+1,n+1});
    for(int i=n;i>=1;i--)
    {
        while(s.top().ff<=a[i])s.pop();
        c[i]=s.top().ss;
        s.push({a[i],i});
    }
}
void prev_lowest(ll int a[],ll int c[],ll int n)
{
    stack<pa>p;
    p.push({-1,0});
    for(int i=1;i<=n;i++)
    {
        while(p.top().ff>=a[i])p.pop();
        c[i]=p.top().ss;
        p.push({a[i],i});
    }
}
int main()
{
    fast;
    ll int te,i,j,k,n,m,w,z,l,r,x,y;
    te=1;
    cin>>te;
    fr(w,te,1)
    {
        cin>>n;
        fr(i,n,1)cin>>a[i],dp[i]=0;
        next_lowest(a,b,n);
        prev_lowest(a,c,n);
        fr(i,n,1)
        {
            dp[a[i]]=max(dp[a[i]],b[i]-c[i]-1);
        }
        d[0]=n+1;
        fr(i,n,1)d[i]=min(dp[i],d[i-1]);
        fr(i,n,1)
        {
            if(d[n-i+1]>=i)cout<<1;
            else cout<<0;
        }
        cout<<endl;
    }
}


