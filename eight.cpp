/*
Implement subset sum problem
*/

#include<bits/stdc++.h>
using namespace std;

bool isSubsetSum(vector<int>arr, int sum)
{
    int n = arr.size();
    vector<vector<bool>> dp(n+1, vector<bool> (sum+1, false));
    
    //base case
    for(int i=0; i<=n; i++)
    {
        dp[i][0] = true;
    }
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=sum; j++)
        {
            if(j >= arr[i-1])
                dp[i][j] = dp[i-1][j] or dp[i-1][j-arr[i-1]];
            else 
                dp[i][j] = dp[i-1][j];  
        }
    }
    
    return dp[n][sum];
}

int main()
{
    vector<int> arr = {4, 2, 8, 9, 11};
    int s1 = 13;
    cout<<"This sum " << s1 << "exists : the function gives : ";
    cout<<isSubsetSum(arr, s1);
    cout<<endl;

    int s2 = 7;
    cout<<"This sum " << s2 << "exists : the function gives : ";
    cout<<isSubsetSum(arr, s2);
    cout<<endl;
}