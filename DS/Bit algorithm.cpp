#include<bits/stdc++.h>
using namespace std;
int tree[500005];
void update(int ind,int x,int n)
{
    while(ind<=n)
    {
        tree[ind]+=x;//tree[ind]=max(tree[ind],x);
        ind+=ind&(-ind);
    }
}
int query(int idx)
{
    int sum=0;
    while(idx>0)
    {
        sum+=tree[idx];//sum=max(sum,tree[idx])
             idx -=idx &(-idx);
    }
    return sum;
}
int main()
{
    int a[100004],n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        update(i,a[i],n);
    }
    cout<<query(5)<<endl;
}
