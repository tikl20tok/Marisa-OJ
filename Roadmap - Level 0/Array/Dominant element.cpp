#include<bits/stdc++.h>
using namespace std;
/*
just prefix max from right to left, monitoring its change
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin>>n;
    vector<long long> a(n+5);
    long long best=-2e18;
    long long i;
    for (i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    best=a[n];//due to the final element cannot be compared
    long long dem=0;
    for (i=n-1;i>=1;i--)
    {
        if (a[i]>best)
        {
            best=a[i];
            dem+=1;
        }
    }
    cout<<dem;

    //full ac 100%



    return 0;
}
