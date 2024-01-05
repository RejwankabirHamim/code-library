#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int mu[mx];
vector <int> prime;
bool vis[mx];
void sieve() {
    int x=sqrt((int)mx);
    for(int i=3; i<=x; i+=2) {
        if(vis[i]==0) {
            for(int j=i*i; j<mx; j+=2*i)
                vis[j]=1;
        }
    }
    prime.push_back(2);
    for(int i=3; i<mx; i+=2)
        if(vis[i]==0)
            prime.push_back(i);
}
void mobius() {
    for(int i=1; i<mx; i++) mu[i]=1;
    int root=sqrt((int)mx);
    for(int i=0; i<prime.size() && prime[i]<=root; i++) {
        int x=prime[i];
        x=x*x;
        for(int j=x; j<mx; j+=x)
            mu[j]=0;
    }
    for(int i=0; i<prime.size(); i++) {
        int x=prime[i];
        for(int j=x; j<mx; j+=x)
            mu[j]*=-1;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
