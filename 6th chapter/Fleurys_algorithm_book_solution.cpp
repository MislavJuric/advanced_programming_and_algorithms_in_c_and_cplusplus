/*
  Exercise taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Pages 255-256

  Snow fell in a city and it needs to be cleaned off the roads. There are n cities and m one-way roads. Print a path through which the snowtruck can clean every road just once.
  That path will exist. In the first line of the input, n (1 <= n <= 1000) and m (1 <= m <= n*n) will be inputted. Then numbers a and b (0 <= a,b < n) are inputted m times. They mark the connection
  of the cities a and b with a road.

  The solution here is the book's solution.
 */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<int> path;

void euler(int node)
{
  int where;
  while (!graph[node].empty())
  {
    where = graph[node].back();
    graph[node].pop_back();
    euler(where);
    path.push_back(node);
  }
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> vi;
  graph.insert(graph.begin(), n, vi); // list of neighbours
  int a, b;
  for (int i = 0; i < m; i++)
  {
    cin >> a >> b;
    graph[b].push_back(a); // we flip the connections because the algorithm creates the path in reverse direction
  }
  euler(0);

  for (int i = 0; i < path.size(); i++)
  {
    cout << path[i] << " ";
  }
  cout << endl;
  return 0;
}
