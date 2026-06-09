#include<bits/stdc++.h>
using namespace std;
/*
we just need to simulate the division in grade 1 due to k is small enough to do that
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long a,b,k;
    cin>>a>>b>>k;
    a%=b;//to make a<b to get the decimal point lol
    long long i;
    for (i=1;i<=k;i++)
    {
        a*=10;
        if (i==k)
            cout<<a/b;//the i-th number in decimal point
        a%=b;
    }
    //full ac 100%


    return 0;
}
