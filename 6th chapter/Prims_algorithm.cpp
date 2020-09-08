/*
  Exercise taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Page 257

  A little country wants to connect its cities by building roads between them. The goal is that all the cities are connected with as little cost as possible.
  There is n cities in total and there is a plan for building m roads from which some have to be chosen to actually be built. 
  The input data in the first line have the numbers n (1 <= n <= 1000) and m (1 <= m <= n^2).
  Then there's m times a triple of a, b, (0 <= a,b < n) and c (1 <= c <= 1000) which describe a plan for building a two-way road between cities a and b which cost c money.
  Print out the least expensive way to connect all n cities (all cities will be connectable).

  The goal of this task is to find the minimum spanning tree (MST) using Prim's algorithm.

  The solution here is mine (before looking at the book's solution).

  Note: This solution is O(n^3), but it works. If I wanted the solution to be O(n^2) (where n is the number of edges), I'd have to rethink my program design. In the book the solution is implemented
	in O(n^2).
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> visited (n, 0);
  // vector<int> distance (n, 1000000); // magic number - 1000000 is the largest distance
  vector<pair<int, int>> vpii;
  vector<vector<pair<int, int>>> graph (n, vpii); // not sure if this is the right way to initialize
  for (int i = 0; i < m; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    graph[a].push_back(make_pair(b, c));
    graph[b].push_back(make_pair(a, c));
  }
  // start from an arbitrary node - let's pick node 0
  visited[0] = 1;
  // distance[0] = 0;
  int total_mst_cost = 0;

  // Prim's algorithm
  bool all_visited = false;
  while (all_visited == false)
  {
    int min_distance = 1000000;
    int node_to_visit = -1;
    for (int i = 0; i < visited.size(); i++)
    {
      if (visited[i] == 1)
      {
	for (int j = 0; j < graph[i].size(); j++)
	{
	  if ((visited[graph[i][j].first] == 0) && (graph[i][j].second < min_distance))
	  {
	    min_distance = graph[i][j].second;
	    node_to_visit = graph[i][j].first;
	  }
	}
      }
    }
    visited[node_to_visit] = 1;
    total_mst_cost += min_distance;
    all_visited = true;
    for (int i = 0; i < visited.size(); i++)
    {
      if (visited[i] == 0)
      {
	all_visited = false;
	break;
      }
    }
  }
  cout << total_mst_cost << endl;
  return 0;
}
