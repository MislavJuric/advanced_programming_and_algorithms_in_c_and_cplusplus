/*
  Exercise taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Page 246-247

  This is the code from the book that implements the Floyd's algorithm.
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int inf = INT_MAX / 2;
vector<vector<int>> graph;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> vi(n, inf);
  graph.insert(graph.begin(), n, vi);
  for (int i = 0; i < n; i++)
  {
    graph[i][i] = 0;
  }
  int a, b, c;
  for (int i = 0; i < m; i++)
  {
    cin >> a >> b >> c;
    if (c < graph[a][b])
    {
      graph[a][b] = graph[b][a] = c;
    }
  }

  // Floyd's algorithm
  for (int k = 0; k < n; k++)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
	if (graph[i][j] > graph[i][k] + graph[k][j])
	{
	  graph[i][j] = graph[i][k] + graph[k][j];
	}
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << graph[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
