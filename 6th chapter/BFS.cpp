/*
  Code taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Page 251

  This is the implementation of 0-1 BFS, where n is the number of nodes, m is the number of edges, x is the starting node and a, b and c represent an edge from a to b with weight c (c is either 0 or 1).
*/

#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
  int n, m, x;
  cin >> n >> m >> x;
  vector<int> dist(n, 1000000);
  vector<int> visited(n, 0);
  vector<pair<int, int>> vpii; // a vector that stores both the node adjecent to the node at that index and the distance to that node at that index
  vector<vector<pair<int, int>>> graph(n, vpii);
  int a, b, c;
  for (int i = 0; i < m; i++)
  {
    cin >> a >> b >> c;
    graph[a].push_back(make_pair(b, c));
    graph[b].push_back(make_pair(a, c));
  }

  list<pair<int, int>> l;
  int node, distance;
  l.push_back(make_pair(x, 0)); // initialization
  while (!l.empty())
  {
    node = l.back().first;
    distance = l.back().second;
    l.pop_back();
    if (!visited[node])
    {
      visited[node] = 1;
      dist[node] = distance;
    }
    else
    {
      continue;
    }
    for (int i = 0; i < graph[node].size(); i++)
    {
      if (!visited[graph[node][i].first])
      {
	if (graph[node][i].second == 1)
	{
	  l.push_front(make_pair(graph[node][i].first, distance + 1));
	}
	else
	{
	  l.push_front(make_pair(graph[node][i].first, distance));
	}
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    cout << dist[i] << " ";
  }
  return 0;
}
