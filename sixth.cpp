/*
Implement Fractional Knapsack
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> profit = {5, 10, 15, 7, 8, 9, 4};
    vector<int> weights = {1, 3, 5, 4, 1, 3, 2};
    int n = profit.size();
    int w = 15;

    multimap<float, pair<int, int>> mp;
    for(int i=0; i<n; i++)
    {
        float pbw = float(profit[i])/float(weights[i]);
        pair<int, int> p = make_pair(weights[i], profit[i]);
        mp.insert({pbw, p});
    }

    auto it = mp.end();
    it--;
    int totalProfit = 0;
    while(w != 0)
    {
        cout<<(it->first)<<endl;
        totalProfit += (it->second).second;
        w -= (it->second).first;
        it--;
        if(it == --mp.begin()) break;
    }

    cout<<"Total Profit is : "<<totalProfit<<endl;
}