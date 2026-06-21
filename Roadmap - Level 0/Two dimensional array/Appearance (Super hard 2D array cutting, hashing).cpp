#pragma GCC optimize("03")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
using namespace std;
/*
it kinda hard to know the best complexity for it: n*m is the best one
it refer to hashing, and just remember since we can't demonstrate it

for example:
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0

at (2,3), you hash all left

and then for example, you want: r1=1;r2=2;c1=2;c3=2 you just need to get the hash of
(2,3) and then subtract the top, the left, the 45 degrees, each divide by 90 degrees

hash:
$$\text{PrefH}[i][j] = \left( \text{PrefH}[i-1][j] \cdot P + \text{PrefH}[i][j-1] \cdot Q - \text{PrefH}[i-1][j-1] \cdot P \cdot Q + A[i][j] \right) \pmod{\text{MOD}}$$

*/

//here is an AI code for experiment

// Configuration Constants
const long long MOD = 1e9 + 7;
const long long P = 31; // Vertical Base (Row shifter)
const long long Q = 37; // Horizontal Base (Column shifter)
/*
in the formula, P and Q are prime numbers, it MUST IS PRIME NUMBER
*/

const int MAX = 1005; // Adjust based on maximum grid size (N, M <= 1000)
long long powP[MAX], powQ[MAX];
long long PrefH[MAX][MAX], PrefB[MAX][MAX];//H currently == A


// Precompute powers of P and Q under MOD
/*
it means P^(current row), Q also but is column
*/
void initPowers(int numRows, int numCols) {
    powP[0] = 1;
    powQ[0] = 1;

    for (int i = 1; i <= numRows; i++) {
        powP[i] = (powP[i - 1] * P) % MOD;
    }
    for (int j = 1; j <= numCols; j++) {
        powQ[j] = (powQ[j - 1] * Q) % MOD;
    }
}

// Build the 2D Prefix Hash Grid
// Added long long PrefH[MAX][MAX] as a parameter so it can work for both PrefH and PrefB
void buildPrefixHash(const vector<vector<long long>>& Mat, long long Pref[MAX][MAX], long long numRows, long long numCols) {
    for (long long i = 1; i <= numRows; i++) {
        for (long long j = 1; j <= numCols; j++) {
            // Replaced hardcoded PrefH with the local 'Pref' array parameter
            long long top = (Pref[i - 1][j] * P) % MOD;
            long long left = (Pref[i][j - 1] * Q) % MOD;
            long long topLeft = (((Pref[i - 1][j - 1] * P) % MOD) * Q) % MOD;
            
            // Your input matrices in main are 1-indexed (i=1; i<=n), so read Mat[i][j] directly!
            long long currentCell = Mat[i][j]; 

            Pref[i][j] = (top + left - topLeft + currentCell) % MOD;
            if (Pref[i][j] < 0) Pref[i][j] += MOD;
        }
    }
}

// Extract the unique hash of any subgrid window in O(1) time
long long getWindowHash(long long r1, long long c1, long long r2, long long c2) {
    long long lenR = r2 - r1 + 1;
    long long lenC = c2 - c1 + 1;

    long long whole = PrefH[r2][c2];
    long long top = (PrefH[r1 - 1][c2] * powP[lenR]) % MOD;
    long long left = (PrefH[r2][c1 - 1] * powQ[lenC]) % MOD;
    long long topLeft = ((PrefH[r1 - 1][c1 - 1] * powP[lenR]) % MOD * powQ[lenC]) % MOD;

    // Execution of the 4-point extraction formula with positive padding
    long long hashValue = (whole - top - left + topLeft + 2 * MOD) % MOD;

    return hashValue;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<long long>> A(MAX,vector<long long> (MAX)),B(MAX,vector<long long> (MAX));
    long long i,j;
    long long n,m,x,y;
    cin>>n>>m>>x>>y;
    for (i=1;i<=n;i++)//rows
        for (j=1;j<=m;j++)//collumn
        {
            cin>>A[i][j];
        }
    for (i=1;i<=x;i++)//rows
        for (j=1;j<=y;j++)
        {
            cin>>B[i][j];
        }

    initPowers(max(n, x), max(m, y));
    buildPrefixHash(A, PrefH, n, m);
    buildPrefixHash(B, PrefB, x, y);

    long long hashB = PrefB[x][y];

    bool found = false;

    // Slide the window across Matrix A
    for (long long i = 1; i <= n - x + 1; i++)
    {
        for (long long j = 1; j <= m - y + 1; j++)
        {
            // Cut out a subgrid matching B's dimensions
            long long currentWindowHash = getWindowHash(i, j, i + x - 1, j + y - 1);

            if (currentWindowHash == hashB) {
                found = true;
                break;
            }
        }
        if (found)
            break;
    }

    if (found)
        cout << "YES";
    else
        cout << "NO";


    //full ac 100%


    return 0;
}
