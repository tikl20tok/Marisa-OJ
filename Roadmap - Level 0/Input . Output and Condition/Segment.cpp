#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<pair<long long,long long>> a(4);
    cin>>a[1].first>>a[1].second>>a[2].first>>a[2].second;
    bool kt=true;
    /*
    ta nên check xem ko thuộc thì nó dễ hơn?
    nó hỏi có điểm chung ko
    -> điểm chung là khi 1 trong 2 điểm của đoạn thẳng này thuộc đoạn thẳng kia
    -> chứng minh nó ko thuộc đoạn thẳng nào đó là được

    cứ sort theo điểm ban đầu đã
    với lại kiểu này luôn đảm bảo a<=b và c<=d, ko lo
    */
    sort(a.begin()+1,a.begin()+1+2);

    if (a[2].first>a[1].second)
        kt=false;

    if (kt)
        cout<<"YES";
    else
        cout<<"NO";

    //FULL AC 100%





    return 0;
}
