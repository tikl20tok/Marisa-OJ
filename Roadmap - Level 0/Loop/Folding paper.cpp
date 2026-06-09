#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin>>n;
    vector<long long> a(70,1);
    long long i;
    for (i=1;i<=61;i++)
    {
        a[i]=a[i-1]*2;
    }
    /*
    gập giấy là j đó cực quen thuộc rồi, bản chất là nhân 2 liên tục
    -> lũy thừa của 2
    duyệt trâu cũng được, vô cùng ez
    */
    for (i=0;i<=61;i++)//lưu ý là giấy đã được gập sẵn 1 cm rồi, lol, nên duyệt từ 0
    {
        if (a[i]>=n)
        {
            cout<<i;
            break;
        }
    }
    
    //full ac100%




    return 0;
}
