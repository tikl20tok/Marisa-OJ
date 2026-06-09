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

    long long index=1;
    for (index=1;index<min(pos.size(),neg.size());index++)
    {
        cout<<neg[index]<<" "<<pos[index]<<" ";
    }
    //process the remains
    //index currently is +1 so don't worry about similarity
    for (i=index;i<neg.size();i++)
    {
        cout<<neg[i]<<" ";
    }
    for (i=index;i<pos.size();i++)
    {
        cout<<pos[i]<<" ";
    }


    //full ac 100%



    return 0;
}
