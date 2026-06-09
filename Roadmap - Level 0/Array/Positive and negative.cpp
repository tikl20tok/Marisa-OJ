#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin>>n;
    vector<long long> pos,neg;
    pos.reserve(n+5);
    pos.push_back(0);
    neg.reserve(n+5);
    neg.push_back(0);
    long long i,j;
    for (i=1;i<=n;i++)
    {
        cin>>j;
        if (j<0)
            neg.push_back(j);
        else
            pos.push_back(j);
    }
    j=1;
    bool kt=true;
    for (i=1;i<neg.size();i++)
    {
        if (kt==true)
        {
            cout<<neg[i]<<" ";
            kt=false;
        }
        else
        {
            if (i=neg.size()-1)
            {
                while (j<=pos.size()-1)
                {
                    cout<<pos[j]<<" ";
                    j++;
                }
                continue;
            }

            if (j<=pos.size())
            {
                cout<<pos[j]<<" ";
                j++;
                kt=true;
                continue;
            }
            kt=false;
        }

    }




    return 0;
}
