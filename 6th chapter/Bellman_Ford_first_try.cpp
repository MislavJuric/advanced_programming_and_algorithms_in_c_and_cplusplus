/*
  Exercise taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Page 249

  In the first line there are three numbers: n (1 <= n <= 200), m (1 <= m <= n * n) and x (0 <= x < n). n is the number of nodes and m is the number of the edges in the graph.
  We then input 3 numbers a, b (0 <= a,b < n) and c (-1000 <= c <= 1000) m times. a and b are 0-indexed nodes connected with a directed edge (from a to b) with weight c.
  Print out the shortest distance from the node x to every other node (every node will be reachable from x) or ERR if there is a negative cycle.

  The solution here is mine, written before I looked at the book's solution.

  I forgot to add dist[x] = 0 at my first try and added that line after looking at the book. I also didn't implement the negative cycle detection.
*/

#include <iostream>
#include <climits>

using namespace std;

constexpr int INF = INT_MAX / 2;

int main()
{
  int n, m, x;
  cin >> n >> m >> x;
  int adjecency_matrix[200][200];
  int min_distance[200];
  for (int i = 0; i < 200; i++)
  {
    min_distance[i] = INF;
    for (int j = 0; j < 200; j++)
    {
      adjecency_matrix[i][j] = INF;
    }
  }
  for (int i = 0; i < 200; i++)
  {
    adjecency_matrix[i][i] = 0;
  }
  for (int i = 0; i < m; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    adjecency_matrix[a][b] = c;
  }
  // Bellman-Ford without negative cycle detection
  min_distance[x] = 0; // forgot to add this in my first try
  for (int i = 0; i < (n - 1); i++)
  {
    for (int j = 0; j < n; j++)
    {
      for (int k = 0; k < n; k++)
      {
	if (min_distance[k] > (min_distance[j] + adjecency_matrix[j][k]))
	{
	  min_distance[k] = min_distance[j] + adjecency_matrix[j][k];
	}
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    cout << min_distance[i] << " ";
  }
  cout << endl;
  return 0;
}
