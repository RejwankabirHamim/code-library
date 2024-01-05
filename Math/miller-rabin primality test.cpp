#include<bits/stdc++.h>
using namespace std;
using u64 = uint64_t;
u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u64)result * base % mod;
        base = (u64)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u64)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(u64 n) { // returns true if n is probably prime, else returns false.
    if (n < 4)
        return n == 2 || n == 3;
    int s = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }
    for (int a:{2, 3, 5, 7, 11, 13, 17, 19, 23,29,31,37}) {
        if(n==(u64)a)return true;
        if (check_composite(n, a, d, s))
            return false;
    }
    return true;
}
int main()
{
    long long int t,i,j,k,x,y,z,n,m,ans,mx=0;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=n;;i--)
        {
            if(MillerRabin(i))
            {
                cout<<i<<endl;
                break;
            }
        }
    }
}
