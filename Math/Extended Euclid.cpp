#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
// for ax+by=c where a,b,c given determine value of x,y
bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}
int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     int a,b,c,x,y,g;
     cin>>a>>b>>c;
     if(find_any_solution(a,b,c,x,y,g))cout<<"No solution exist"<<endl;
     else cout<<x<<" "<<y<<endl;
}
