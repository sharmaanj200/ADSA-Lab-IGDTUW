/*
Program 1:
Write a program to read, print, add, subtract and multiply 2 matrices. Read the sizes also from user.
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> subtract(vector<vector<int>> &matrix1, vector<vector<int>> &matrix2, int n, int m, int p, int q)
{
    vector<vector<int>> ans(n, vector<int> (m, -1));

    if(n == p and m == q)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                ans[i][j] = matrix1[i][j] - matrix2[i][j];
            }
        }
    }

    return ans;
}


vector<vector<int>> multiply(vector<vector<int>> &matrix1, vector<vector<int>> &matrix2, int n, int m, int p, int q)
{
    vector<vector<int>> ans(n, vector<int> (q, 0));

    if(m == p)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<q; j++)
            {
                for(int k=0; k<m; k++)
                {
                    ans[i][j] += (matrix1[i][k] * matrix2[k][j]);
                }
            }

        }
    }

    return ans;
}


vector<vector<int>> add(vector<vector<int>> &matrix1, vector<vector<int>> &matrix2, int n, int m, int p, int q)
{
    vector<vector<int>> ans(n, vector<int> (m, -1));

    if(n == p and m == q)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                ans[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
    }

    return ans;
}

int main()
{
    int n, m;
    cout<<"Enter dimensions of first matrix"<<endl;
    cin>>n>>m;

    int p, q;
    cout<<"Enter dimensions of second matrix"<<endl;
    cin>>p>>q;


    vector<vector<int>> matrix1(n, vector<int> (m));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            int x;
            cin>>x;
            matrix1[i][j] = x;
        }
    }

    vector<vector<int>> matrix2(p, vector<int> (q));
    for(int i=0; i<p; i++)
    {
        for(int j=0; j<q; j++)
        {
            int x;
            cin>>x;
            matrix2[i][j] = x;
        }
    }

    //adding the two matrices
    vector<vector<int>> ans1 = add(matrix1, matrix2, n, m, p, q);

    //subtract the matrices
    vector<vector<int>> ans2 = subtract(matrix1, matrix2, n, m, p, q);

    //multiply the matrices
    vector<vector<int>> ans3 = multiply(matrix1, matrix2, n, m, p, q);

    cout<<"After Addition : "<<endl;
    for(auto vec: ans1)
    {
        for(auto num: vec) cout<<num<<" ";
        cout<<endl;
    }

    cout<<endl;

    cout<<"After Subtraction : "<<endl;
    for(auto vec: ans2)
    {
        for(auto num: vec) cout<<num<<" ";
        cout<<endl;
    }

    cout<<endl;

    cout<<"After Multiplication : "<<endl;
    for(auto vec: ans3)
    {
        for(auto num: vec) cout<<num<<" ";
        cout<<endl;
    }

    cout<<endl;
}