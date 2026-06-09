#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin>>n;
    /*
    we have even*5 give 1 zero
    and we can demonstrate that even number always more than 5 in quantantiy

    and so how to count 5
    we need to see that it is sum like this:
    1*5=5
    2*5=10
    3*5=15
    4*5=20
    5*5=25

    we have zero in n!
    (all floor down each)
    = n/5 + n/25 + n/125 + n/5^4...
    you see that you got the zero first now, so if you want to make zero in the n!
    you need n/5^?
    so what we will do is count how many time n can divide by 5 till zero
    and each
    */
    long long count=0;
    while (n>0)
    {
        count+=n/5;
        n/=5;
    }
    cout<<count;
    
    //full ac 100%



    return 0;
}
