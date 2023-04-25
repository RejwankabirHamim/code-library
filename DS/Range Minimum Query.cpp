#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define K 20
long long st[MAXN][K + 1];
int arr[MAXN],lg[MAXN];
int main()
{
    lg[1] = 0;
    for (int i = 2; i < MAXN; i++)
        lg[i] = lg[i/2] + 1;
    int i,j,k,n,m,x,y,z;
    cin>>n;
    for(i=0;i<n;i++)cin>>arr[i];
    for (int i = 0; i < n; i++)
        st[i][0] = arr[i];
    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            st[i][j] =min(st[i][j-1],st[i + (1 << (j - 1))][j - 1]);
    cin>>m;
    while(m--)
    {
        int L,R;
        cin>>L>>R;
        int j = lg[R - L + 1];
        int minimum = min(st[L][j], st[R - (1 << j) + 1][j]);
        cout<<minimum<<endl;
    }
}


