#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long d;
    cin>>d;
    /*
    giây = giờ * 3600 + phút * 60 + giây
    -> giờ = giây / 3600, lấy phần dư ra
    -> phút = dư /60, lấy phần dư ra
    -> giây là phần dư
    */
    long long h,m,s,du;
    h=d/3600;
    du=d%3600;
    m=du/60;
    du=du%60;
    s=du;
    cout<<h<<" "<<m<<" "<<s;




    return 0;
}
