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
long long PrefH[MAX][MAX], PreB[MAX][MAX];//H currently == A


// Precompute powers of P and Q under MOD
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
void buildPrefixHash(const vector<vector<int>>& A, int numRows, int numCols) {
    for (int i = 1; i <= numRows; i++) {
        for (int j = 1; j <= numCols; j++) {
            // Formula: Top*P + Left*Q - TopLeft*P*Q + CurrentCell
            long long top = (PrefH[i - 1][j] * P) % MOD;
            long long left = (PrefH[i][j - 1] * Q) % MOD;
            long long topLeft = (((PrefH[i - 1][j - 1] * P) % MOD) * Q) % MOD;
            long long currentCell = A[i - 1][j - 1]; // Input A is 0-indexed
            
            // Combine and apply modulo safely
            PrefH[i][j] = (top + left - topLeft + currentCell) % MOD;
            
            // Handle potential negative values from the subtraction step
            if (PrefH[i][j] < 0) PrefH[i][j] += MOD;
        }
    }
}

// Extract the unique hash of any subgrid window in O(1) time
long long getWindowHash(int r1, int c1, int r2, int c2) {
    int lenR = r2 - r1 + 1;
    int lenC = c2 - c1 + 1;

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
    buildPrefixHash(A, PrefHA, n, m);
    buildPrefixHash(B, PrefHB, x, y);

    long long hashB = PrefHB[x][y];

    bool found = false;

    // Slide the window across Matrix A
    for (int i = 1; i <= n - x + 1; i++) 
    {
        for (int j = 1; j <= m - y + 1; j++) 
        {
            // Cut out a subgrid matching B's dimensions
            long long currentWindowHash = getWindowHashA(i, j, i + x - 1, j + y - 1);
            
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



    return 0;
}
