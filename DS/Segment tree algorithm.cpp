#include <bits/stdc++.h>
using namespace std;
int a[1001];
int t[800001];
void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}
int query(int v, int tl, int tr, int l, int r)//query
{
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return query(v*2, tl, tm, l, min(r, tm))
           + query(v*2+1, tm+1, tr, max(l, tm+1), r);
}
void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}
int main()
{
    int n,i,j,k;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];
    build(1, 1, n);
    update(1, 1, n, 2, 0);
    cout << query(1, 1, n, 1, 3) << endl;
    update(1, 1, n, 2, 2);
    cout << query(1, 1, n, 2, 2) << endl;
}
