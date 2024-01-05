#include<bits/stdc++.h>
using namespace std;
bool prime[1000000];
int f[30];
int h;
void seive_prime(int n)
{
    int sq=sqrt(n),i,j;
    prime[1]=1;
    for(i=4;i<=n;i+=2)
        prime[i]=1;
    for(i=3;i<=sq;i+=2)
    {
        if(prime[i]==0)
        {
            for(j=i*i;j<=n;j+=i)
            {
                prime[j]=1;
            }
        }
    }
}
void factor(int a)
{
    int i,j;
    h=0;
    while(a!=1)
    {
        if(prime[a]==0)
        {
            h++;
            f[h]=a;

            a=1;
        }
        else
        {
             for(i=2;i<=sqrt(a);i++)
             {
                if(prime[i]==0&&a%i==0)
                {
                    a=a/i;
                    h++;
                    f[h]=i;
                    break;
                }
            }
        }
    }
    return;

}
int main()
{
    seive_prime(100000);

    long long int n,i,k,m,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        factor(n);
        m=1;
        for(i=1;i<=h;i++)
        {
            k=1;
            while(f[i]==f[i+1])
            {
                k++;
                i++;
                if(i==h)
                    break;
            }
            m=m*(k+1);
        }
        cout<<m<<endl;
    }

    return 0;
}
