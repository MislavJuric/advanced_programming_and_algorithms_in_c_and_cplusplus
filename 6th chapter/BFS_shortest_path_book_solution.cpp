/*
  Exercise taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Page 252-253

  Two numbers are inputted: n (1 <= n <= 1000) and m (1 <= m <= 1000) and then n lines with m characters. Every character is a '.' or a 'x' or a '#'.
  Those characters describe the plan of the environment. '.' represents a walkable path and when we go through this field we don't spend any time.
  'x' represents a forest through which we need 1 hour to pass, while a '#' is a rock through which we can't pass through. How many hours do we need
  to go from the upper-left field to the lower-right field as fast as possible? From a given field we can cross over to any of the adjacent 8 fields
  (if we can pass through that field). Upper left and down right field will be the grass and it will be possible to go from the one to the other.

  The solution here is taken from the book.
*/

#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

const int directionx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int directiony[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main()
{
  int n, m;
  cin >> n >> m;
  vector<string> terrain(n);
  for (int i = 0; i < m; i++)
  {
    cin >> terrain[i];
  }

  list<pair<pair<int, int>, int>> l; // the data structure within the list looks like this: ((x,y), distance)
  int x, y, distance, newx, newy;
  // initialization
  l.push_back(make_pair(make_pair(0,0), 0));
  while (!l.empty())
  {
    x = l.back().first.first;
    y = l.back().first.second;
    distance = l.back().second;
    l.pop_back();
    if (x == n - 1 && y == m - 1) // if we reached the solution
    {
      cout << distance << endl;
      return 0;
    }
    if (terrain[x][y] != '#')
    {
      terrain[x][y] = '#'; // with a # we mark where we have already been
    }
    else
    {
      continue;
    }
    for (int i = 0; i < 8; i++) // spread to surrounding places
    {
      newx = x + directionx[i];
      newy = y + directiony[i];
      if (newx < 0 || newx >= n || newy < 0 || newy >= m)
      {
	continue;
      }
      if (terrain[newx][newy] != '#')
      {
	if (terrain[newx][newy] == 'x')
	{
	  l.push_front(make_pair(make_pair(newx, newy), distance+1));
	}
	else
	{
	  l.push_back(make_pair(make_pair(newx, newy), distance));
	}
      }
    }
  }
  return 0;
}
