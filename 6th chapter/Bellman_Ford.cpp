/*
  Exercise taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Page 249

  In the first line there are three numbers: n (1 <= n <= 200), m (1 <= m <= n * n) and x (0 <= x < n). n is the number of nodes and m is the number of the edges in the graph.
  We then input 3 numbers a, b (0 <= a,b < n) and c (-1000 <= c <= 1000) m times. a and b are 0-indexed nodes connected with a directed edge (from a to b) with weight c.
  Print out the shortest distance from the node x to every other node (every node will be reachable from x) or ERR if there is a negative cycle.

  The solution here is from the book.
*/

#include <iostream>
#include <vector>

using namespace std;

int graph[40000][3]; // an array of edges

int main()
{
  int n, m, x;
  cin >> n >> m >> x;
  vector<int> dist(n, 1000000); // 1000000 is INF (infinity; a very large number)
  for (int i = 0; i < m; i++)
  {
    cin >> graph[i][0] >> graph[i][1] >> graph[i][2];
  }
  dist[x] = 0; // Bellman-Ford initialization (I don't have this in my solution)
  for (int i = 0; i < (n - 1); i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (dist[graph[j][1]] > dist[graph[j][0]] + graph[j][2])
      {
	dist[graph[j][1]] = dist[graph[j][0]] + graph[j][2];
      }
    }
  }
  for (int j = 0; j < m; j++) // search for negative cycles
  {
    if (dist[graph[j][1]] > dist[graph[j][0]] + graph[j][2])
    {
      cout << "ERR" << endl;
      return 0;
    }
  }
  for (int i = 0; i < n; i++)
  {
    cout << dist[i] << " ";
  }
  cout << endl;
  return 0;
}
