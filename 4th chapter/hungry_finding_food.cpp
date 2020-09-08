/*
  Task text taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Page 179-180

  Two numbers, n and m (1 <= n, m <= 1000) are inputted, which represent the dimensions of a plan of a city which is being inputted.
  After that n lines with m characters is inputted which represent the outline of the city. The inputted characters can be either '.', 'X', 'o' or '-'.
  '.' represents a road, 'X' represents a building, 'o' is food (burek) and '-' is the Hungry. You can walk on roads ('.'), but you can't walk on buildings ('X').
  The Hungry can move up, down, left and right through the city.
  Print the maximum number of food (bureks) the Hungry can eat and what is the least amount of steps that the Hungry must make so that he can come from
  the starting location to every food (burek) he can eat. 

  Note: The "least amount of steps" is actually the food which has the most distance from the Hungry's starting position.

  I wrote this before looking at the book's solution. 

  This code doesn't work - it has a bug somewhere, so at one point I decided to look at the book's solution because this took too much time to debug
*/


#include <iostream>
#include <queue>
#include <set>

using namespace std;

struct Coordinate
{
  int x;
  int y;

  Coordinate(int x_arg, int y_arg)
  {
    x = x_arg;
    y = y_arg;
  }
};

bool operator < (const Coordinate& c1, const Coordinate& c2) 
{
  if (c1.x != c2.x)
  {
    return (c1.x < c2.x);
  }
  else
  {
    return (c1.y < c2.y);
  }
}

char map[1000][1000];
int n, m;
int max_depth = 0;
int food_count = 0;
queue<Coordinate> q;
set<Coordinate> visited;
int Hungry_x, Hungry_y;

void bfs(int depth) 
{
  if (q.empty())
  {
    return;
  }
  Coordinate current = q.front();
  q.pop();
  if ((current.x < 0) || (current.x >= n) || (current.y < 0) || (current.y >= m))
  {
    return;
  }
  visited.emplace(current.x, current.y);
  if (map[current.x][current.y] == 'o')
  {
    if (max_depth < depth)
    {
      max_depth = depth;
    }
    food_count++;
  }
  if((map[current.x + 1][current.y] != 'X') && (visited.find(Coordinate{current.x + 1, current.y}) == visited.end()))
  {
    q.emplace(current.x + 1, current.y);
  }
  if((map[current.x -1][current.y] != 'X') && (visited.find(Coordinate{current.x - 1, current.y}) == visited.end()))
  {
    q.emplace(current.x - 1, current.y);
  }
  if((map[current.x][current.y + 1] != 'X') && (visited.find(Coordinate{current.x, current.y + 1}) == visited.end()))
  {
    q.emplace(current.x, current.y + 1);
  }
  if((map[current.x][current.y - 1] != 'X') && (visited.find(Coordinate{current.x, current.y - 1}) == visited.end()))
  {
    q.emplace(current.x, current.y - 1);
  }
  bfs(depth + 1); // doesn't work as expected
}

int main()
{
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> map[i][j];
      if (map[i][j] == '-')
      {
	Hungry_x = i;
	Hungry_y = j;
      }
    }
  }
  q.push(Coordinate{Hungry_x, Hungry_y});
  bfs(0);
  cout << "Max depth is " << max_depth << endl;
  cout << "Food count is " << food_count << endl;
  return 0;
}
