//Range sum query
//https://cp-algorithms.com/data_structures/sparse-table.html
#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define K 20
long long st[MAXN][K + 1];
int main()
{

    for (int i = 0; i < N; i++)
        st[i][0] = array[i];

    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1 << j) <= N; i++)
            st[i][j] = st[i][j-1] + st[i + (1 << (j - 1))][j - 1];
    long long sum = 0;
    for (int j = K; j >= 0; j--) {
        if ((1 << j) <= R - L + 1) {
            sum += st[L][j];
            L += 1 << j;
        }
    }
}


