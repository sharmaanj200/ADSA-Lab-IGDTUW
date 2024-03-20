#include<bits/stdc++.h>
using namespace std;

int gap = 2;
int delta = 1;
int sequence_alignment(string x, string y, int n, int m, vector<vector<int>> &dp)
{

    //Initialization
    for(int i=0; i<n; i++)
    {
        dp[0][i] = gap;
    }

    for(int j=0; j<m; j++)
    {
        dp[j][0] = gap;
    }

    dp[0][0] = 0;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(x[i-1] == y[j-1]) dp[i][j] = dp[i-1][j-1];
            else {
                dp[i][j] = min(delta + dp[i-1][j-1], min(gap + dp[i-1][j], gap + dp[i][j-1]));
            }
        }
    }

    return dp[n][m];
}


int main()
{
    string x = "PEST";
    string y = "PEACE";
    int n = x.length();
    int m = y.length();
    vector<vector<int>> dp(n+1, vector<int> (m+1));
    int ans = sequence_alignment(x, y, n, m, dp);
    cout<<"Total penalty is : "<<ans;
}