#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
using namespace std;
long long n, m;
vector<vector<long long>> a(1000+5, vector<long long>(1000+5,0));

long long upleft(long long i, long long j, long long sum)
{
    sum+=a[i][j];
    if (i==1 || j==1)
    {
        return sum;
    }
    else
    {
        return upleft(i-1, j-1, sum);
    }
}
long long upright(long long i, long long j, long long sum)
{
    sum+=a[i][j];
    if (i==1 || j==m)
    {
        return sum;
    }
    else
    {
        return upright(i-1, j+1, sum);
    }
}
long long downleft(long long i, long long j, long long sum)
{
    sum+=a[i][j];
    if (i==n || j==1)
    {
        return sum;
    }
    else
    {
        return downleft(i+1, j-1, sum);
    }
}
long long downright(long long i, long long j, long long sum)
{
    sum+=a[i][j];
    if (i==n || j==m)
    {
        return sum;
    }
    else
    {
        return downright(i+1, j+1, sum);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("TESTING.INP","r",stdin);
    freopen("TESTING.OUT","w",stdout);
    
    cin >> n >> m;
    long long i, j;
    long long x, y;
    cin>>x>>y;
    
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            cin>>a[i][j];
        }
    }
    long long tong=0;
    tong+=upleft(x, y, 0);
    tong+=upright(x, y, 0);
    tong+=downleft(x, y, 0);
    tong+=downright(x, y, 0);
    /*
    we can better to use normal while loop to avoid overstacking, but the input is small so we can use recursion to make the code more readable
    */
    tong-=3*a[x][y];//because after 4 times of recursion, the a[x][y] is counted 4 times, so we need to minus 3 times of it to get the correct sum
    cout << tong;



    return 0;
}
