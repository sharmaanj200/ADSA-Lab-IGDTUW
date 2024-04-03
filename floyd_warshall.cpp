// C++ Program for Floyd Warshall Algorithm
#include <bits/stdc++.h>
using namespace std;

#define V 4
#define INF 99999
void printSolution(int dist[][V]);

void floydWarshall(int matrix[][V])
{
        int n = V;

	    for(int via=0; via<n; via++)
	    {
	        for(int i=0; i<n; i++)
	        {
	            for(int j=0; j<n; j++)
	                matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
	        }
	    }

        printSolution(matrix);
}


void printSolution(int dist[][V])
{
	cout << "The following matrix shows the shortest "
			"distances"
			" between every pair of vertices \n";
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (dist[i][j] == INF)
				cout << "INF"
					<< " ";
			else
				cout << dist[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int graph[V][V] = { { 0, 5, INF, 10 },
						{ INF, 0, 3, INF },
						{ INF, INF, 0, 1 },
						{ INF, INF, INF, 0 } };

	floydWarshall(graph);
	return 0;
}

