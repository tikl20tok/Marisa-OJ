#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long a,b;
    cin>>a>>b;
    long long tong=a+b;
    string s = to_string(tong);
    bool kt=false;
    for (long long i=s.size()-1;i>=0;i--)
    {
        if (s[i]!='0')
            kt=true;
        if (kt==true)
            cout<<s[i];
    }




    return 0;
}
