#pragma GCC optimize("03")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
using namespace std;
/*
go from 0 to optimized first

*/
bool coordinate[105][105];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin>>n;
    long long i,j,k;
    long long x1,y1,x2,y2;
    memset(coordinate,false,sizeof(coordinate));
    for (k=1;k<=n;k++)
    {
        cin>>x1>>y1>>x2>>y2;
        for (i=x1;i<=x2;i++)
            for (j=y1;j<=y2;j++)
            {
                coordinate[i][j]=true;
            }
    }
    long long dem=0;
    for (i=1;i<=100;i++)
        for (j=1;j<=100;j++)
        {
            if (coordinate[i][j]==true)
                dem+=1;
        }
    cout<<dem;


    //worse code, version 1: Brute-force

    return 0;
}
