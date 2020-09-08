/*
  Exercise taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Page 255

  Snow fell in a city and it needs to be cleaned off the roads. There are n cities and m one-way roads. Print a path through which the snowtruck can clean every road just once.
  That path will exist. In the first line of the input, n (1 <= n <= 1000) and m (1 <= m <= n*n) will be inputted. Then numbers a and b (0 <= a,b < n) are inputted m times. They mark the connection
  of the cities a and b with a road.

  The solution here is mine, generated before looking at the book.

  Note: The solution here for the input given in the book doesn't match the solution this program outputs, but neither does the book's code solution. I think that input and output examples for this code
	may be wrong.
 */

#include <iostream>
#include <vector>

using namespace std;

int adjecency_matrix[1000][1000];
vector<int> path;

bool hasEdges(int node, int n)
{
  for (int i = 0; i < n; i++)
  {
    if (adjecency_matrix[node][i] == 1)
    {
      return true;
    }
  }
  return false;
}

void fleury(int start_node, int n)
{
  while (hasEdges(start_node, n))
  {
    int neighbour_index = -1;
    for (int i = 0; i < n; i++)
    {
      if (adjecency_matrix[start_node][i] == 1)
      {
	adjecency_matrix[start_node][i] = 0;
	neighbour_index = i;
	break;
      }
    }
    fleury(neighbour_index, n);
    path.push_back(start_node);
  }
}

int main()
{
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    adjecency_matrix[a][b] = 1;
  }
  // check for nodes with uneven number of edges
  vector<int> nodes_with_uneven_edges;
  for (int i = 0; i < n; i++)
  {
    int count = 0;
    for (int j = 0; j < n; j++) // adjacency matrix dimension is nxn
    {
      if (adjecency_matrix[i][j] == 1)
      {
	count++;
      }
    }
    if ((count % 2) != 0)
    {
      nodes_with_uneven_edges.push_back(i);
    }
  }
  // if there are any nodes with uneven number of edges (here the graph will necesarrily be semi-eulerian, meaning only 2 nodes with uneven number of edges), start with them
  if (!nodes_with_uneven_edges.empty())
  {
    fleury(nodes_with_uneven_edges[0], n);
  }
  else
  {
    fleury(0, n);
  }
  // print the solution in reverse
  for (int i = path.size() - 1; i >= 0; i--)
  {
    cout << path[i] << " ";
  }
  // if it's a semi-eulerian graph, print the beginning node at the end
  if (!nodes_with_uneven_edges.empty())
  {
    cout << nodes_with_uneven_edges[0];
  }
  cout << endl;
  return 0;
}
