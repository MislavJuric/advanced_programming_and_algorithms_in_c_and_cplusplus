/*
  Exercise taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Page 234

  Find the shortest path between a starting city to every other city and print the distances from the starting city to other cities sorted by their index.
  There is n (1 <= n <= 1000) cities and m (1 <= m <= n*n) roads. Cities are 0-indexed. Input data is n, m and x. x is the starting city.
  Then there is m times three numbers a, b and c (0 <= a, b < n), (1 <= c <= 1000) which describe a two-way road of length c which connects the cities a and b.
  There will be a path from the starting city to every other city.

  Prints out the path from the starting node (city) to the every other node (in reverse), alongside the distances.
*/

#include <iostream>
#include <climits>

using namespace std;

constexpr int INFINITY = INT_MAX/2;

int main()
{
  int distances[1000];
  bool visited[1000];
  int adjecency_matrix[1000][1000];
  int previous[1000];
  int n, m, x;
  cin >> n >> m >> x;
  for (int i = 0; i < n; i++)
  {
    previous[i] = -1;
    distances[i] = INFINITY;
    visited[i] = false;
  }
  distances[x] = 0;
  previous[x] = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      adjecency_matrix[i][j] = INFINITY;
    }
  }
  for (int i = 0; i < m; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    adjecency_matrix[a][b] = c;
    adjecency_matrix[b][a] = c;
  }
  // Dijkstra's algorithm
  bool all_visited = false;
  while (all_visited != true)
  {
    bool check = true;
    for (int i = 0; i < n; i++)
    {
      if (visited[i] == false)
      {
	check = false;
	break;
      }
    }
    all_visited = check;
    if (all_visited == true)
    {
      break;
    }
    int min_index = INFINITY;
    for (int i = 0; i < n; i++)
    {
      if ((distances[i] < min_index) && (visited[i] == false))
      {
	min_index = i;
      }
    }
    visited[min_index] = true;
    for (int i = 0; i < n; i++)
    {
      if (distances[i] > (distances[min_index] + adjecency_matrix[min_index][i]))
      {
	distances[i] = distances[min_index] + adjecency_matrix[min_index][i];
	previous[i] = min_index;
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    bool over = false;
    int current = previous[i];
    cout << i << " ";
    if (i == x) // hack to prevent double output if we are dealing with the starting city
    {
      over = true;
    }
    while (over != true)
    {
      cout << current << " ";
      if (current == x)
      {
	over = true;
      }
      current = previous[current];
    }
    cout << " -> " << distances[i] << " " << endl;
  }
  cout << endl;
  return 0;
}
