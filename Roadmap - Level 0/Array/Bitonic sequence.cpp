#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    /*
    i<j
    a[j]<a[j+1]
    -> ascending
    i>j
    a[j]<a[j-1]
    -> a[j-1]>a[j]
    -> a[j-1+1]>a[j+1]
    -> a[j]>a[j+1]
    -> descending
    */
    ll n;
    cin>>n;
    ll i,j;
    vector<ll> a(n+5,0);
    for (i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    a[0]=a[1];
    a[n+1]=a[n];
    vector<bool> ascending(n+5,false), descending(n+5,false);
    ascending[0]=true;
    ascending[1]=true;
    descending[n+1]=true;
    descending[n]=true;
    for (i=2;i<=n;i++)
    {
        if (a[i]>a[i-1]&&ascending[i-1]==true)
        {
            ascending[i]=true;
        }
    }
    for (i=n-1;i>=1;i--)
    {
        if (a[i]>a[i+1]&&descending[i+1]==true)
        {
            descending[i]=true;
        }
    }
    bool kt=false;
    for (i=1;i<=n;i++)
    {
        if (ascending[i]==true&&descending[i]==true)
        {
            kt=true;
            break;
        }
    }
    if (kt==true)
        cout<<"YES";
    else   
        cout<<"NO";


    //full ac100%

    return 0;
}