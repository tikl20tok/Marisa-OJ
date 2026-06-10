#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n,k;
    cin>>n>>k;
    long long i,j;
    vector<long long> a(n+5);
    k%=n;
    /*
    we can deduce that
    when you rotate the array n times, it will like the begining
    so
    k%n make you know the final
    
    now, we can't make rapid rotation cause n^2 to tle if n so big 10^6
    -> we need think about cycle to count the index

    */
    for (i=1;i<=n;i++)
    {
        cin>>j;
        long long index=(i-k+n)%n;
        if (index==0)
            index=n;
        
        a[index]=j;
    }

    for (i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }




    return 0;
}