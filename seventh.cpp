/*
Implement 0/1 knapsack
*/

#include<bits/stdc++.h>
using namespace std;

int knapSack(int maxWeight, vector<int> &weight, vector<int> &value, int n) 
{ 
    vector<vector<int>> dp(n+1, vector<int> (maxWeight+1, 0));
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=maxWeight; j++)
        {
            if(j >= weight[i-1])
                dp[i][j] = max(value[i-1] + dp[i-1][j-weight[i-1]], dp[i-1][j]);
            else 
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][maxWeight];
}

int main() 
{
    vector<int> profit = {5, 10, 15, 7, 8, 9, 4};
    vector<int> weights = {1, 3, 5, 4, 1, 3, 2};
    int w = 15;
    int n = profit.size();
    int p = knapSack(w, weights, profit, n);
    cout<<"Total Profit is : "<< p <<endl;
}