/*
  Exercise taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Page 252

  Two numbers are inputted: n (1 <= n <= 1000) and m (1 <= m <= 1000) and then n lines with m characters. Every character is a '.' or a 'x' or a '#'.
  Those characters describe the plan of the environment. '.' represents a walkable path and when we go through this field we don't spend any time.
  'x' represents a forest through which we need 1 hour to pass, while a '#' is a rock through which we can't pass through. How many hours do we need
  to go from the upper-left field to the lower-right field as fast as possible? From a given field we can cross over to any of the adjacent 8 fields
  (if we can pass through that field). Upper left and down right field will be the grass and it will be possible to go from the one to the other.

  The solution here is mine, modeled after the book's solution of a similar exercise. The idea was to convert this problem to the one
  the book already has a solution for.

  This is essentially a variant from of the 0-1 BFS algorithm, but with one extra node (which can't be visited). I can compute the distances from (0,0) to 
  all nodes and then take the distance to the lower-right.

  Note: There is a bug somewhere in the computation of the distance to the node
*/

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <utility>

using namespace std;

int coord(int x, int y, int m)
{
  return (x * m + y);
}

int main()
{
  int n, m;
  cin >> n >> m; 
  vector<string> terrain;
  for (int i = 0; i < n; i++)
  {
    string line;
    cin >> line;
    terrain.push_back(line);
  }

  // data structures for 0-1 BFS
  vector<int> dist(n*m, 1000000); // max distance
  vector<int> visited(n*m, 0);
  vector<pair<int, int>> vpii; // node is identified by its coordinates passed to the coord function above
  vector<vector<pair<int,int>>> graph(n*m, vpii);

  // calculate all distances based on the terrain - bug somewhere here... I am not calculating the distance to the adjacent nodes correctly
  list<pair<int,int>> possible_moves {{-1,1}, {0, 1}, {1, 1}, {-1, 0}, {1, 0}, {-1, -1}, {0, -1}, {1, -1}};
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      // can go to any 8 adjacent fields
      for (list<pair<int,int>>::iterator it = possible_moves.begin(); it != possible_moves.end(); it++)
      {
	pair<int, int> move = *it;
	// are we within the map?
	if (((i + move.first) < 0) || ((i + move.first) >= m) || ((j + move.second) < 0) || ((j + move.second) >= n))
	{
	  continue;
	}
	// store the distance in both nodes
	if (terrain[i + move.first][j + move.second] == '.')
	{
	  graph[coord(i, j, m)].push_back(make_pair(coord(i + move.first, j + move.second, m), 0));
	  graph[coord(i + move.first, j + move.second, m)].push_back(make_pair(coord(i, j, m), 0));
	}
	if (terrain[i + move.first][j + move.second] == 'x')
	{
	  graph[coord(i, j, m)].push_back(make_pair(coord(i + move.first, j + move.second, m), 1));
	  graph[coord(i + move.first, j + move.second, m)].push_back(make_pair(coord(i, j, m), 1));
	}
	if (terrain[i + move.first][j + move.second] == '#')
	{
	  continue;
	}
      }
    }
  }

  list<pair<int, int>> l;
  int node;
  int distance;
  l.push_back(make_pair(coord(0, 0, m), 0)); // starting from (0,0) - upper left
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
	  l.push_back(make_pair(graph[node][i].first, distance));
	}
      }
    }
  }
  cout << dist[coord((m - 1), (n - 1), m)] << endl;
  return 0;
}
