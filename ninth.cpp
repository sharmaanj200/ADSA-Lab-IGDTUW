/*
Implement BFS
*/

#include<bits/stdc++.h>
using namespace std;

void BFS(vector<vector<int>> adjList, int start, vector<bool> visited)
{
    queue<int> q;
    q.push(start);
    while(!q.empty())
    {
        int f = q.front();
        q.pop();
        cout<<f<<" ";

        for(auto i: adjList[f])
        {
            if(!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void addEdge(vector<vector<int> >& adjList, int u, int v)
{
    adjList[u].push_back(v);
}

//creating a directed graph
int main()
{
    int n = 6;
    vector<vector<int>> adjList(6);
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 3, 5);
    addEdge(adjList, 4, 2);
    addEdge(adjList, 2, 5);
    addEdge(adjList, 5, 4);

    vector<bool> visited(n+1, false);
    cout<<"ELements in BFS traversal are : ";
    visited[0] = true;
    BFS(adjList, 0, visited);

}