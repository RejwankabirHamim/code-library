#include<bits/stdc++.h>
using namespace std;
int phi(int n)
{
    int result,i,j,k;
    result=n;
    for(i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
                n=n/i;
            result-=result/i;
        }
    }
    if(n>1)
        result-=result/n;
    return result;
}
int main()
{
     int a,b,c,x,y,i,j;
     cin>>a;
     i=0;
     while(a--)
     {
         i++;
         cin>>x>>y;
         b=0;
         for(j=x;j<=y;j++)
         {
             c=phi(j);
             cout<<c<<" ";
             b=b+c;

         }
         cout<<"Case "<<i<<": "<<b<<endl;

     }
}

