/*
  Task text taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Page 180-181

  Two numbers, n and m (1 <= n, m <= 1000) are inputted, which represent the dimensions of a plan of a city which is being inputted.
  After that n lines with m characters is inputted which represent the outline of the city. The inputted characters can be either '.', 'X', 'o' or '-'.
  '.' represents a road, 'X' represents a building, 'o' is food (burek) and '-' is the Hungry. You can walk on roads ('.'), but you can't walk on buildings ('X').
  The Hungry can move up, down, left and right through the city.
  Print the maximum number of food (bureks) the Hungry can eat and what is the least amount of steps that the Hungry must make so that he can come from
  the starting location to every food (burek) he can eat. 

  Note: The "least amount of steps" is actually the food which has the most distance from the Hungry's starting position.

  This is the book's solution.
*/

#include <iostream>

char map[1000][1001];
int number_of_foods, number_of_steps;
int n, m;

int queue[100000];
int beginning, end;

void push(int x)
{
  queue[end] = x;
  end = (end + 1) % 100000;
}


int pop()
{
  int x;
  x = queue[beginning];
  beginning = (beginning + 1) % 100000;
  return x;
}

void BFS(int x, int y)
{
  int i, steps;
  const int directionX[4] {0, 0, -1, 1};
  const int directionY[4] {1, -1, 0, 0};

  beginning = end = 0;
  push(x);
  push(y);
  push(0); // distance from the starting position - I didn't push this in my non-working solution
  while (beginning != end)
  {
    x = pop();
    y = pop();
    steps = pop();
    if (x < 0 || x >= n || y < 0 || y >= m)
    {
      continue;
    }
    if (map[x][y] == '.' || map[x][y] == '-')
    {
      map[x][y] = 'Q'; // Q means we visited a place
    }
    else if (map[x][y] == 'o')
    {
      map[x][y] = 'Q';
      number_of_foods++;
      if (number_of_steps < steps)
      {
	number_of_steps = steps;
      }
    }
    else
    {
      continue;
    }
    for (i = 0; i < 4; i++)
    {
      push(x + directionX[i]);
      push(y + directionY[i]);
      push(steps + 1);
    }
  }
}

int main()
{
  int i, j;
  std::cin >> n >> m;
  for (i = 0; i < n; i++)
  {
     std::cin >> map[i];
  }
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++)
    {
      if (map[i][j] == '-')
      {
	BFS(i, j);
      }
    }
  }
  std::cout << "Hungry can eat " << number_of_foods << " bureks. The most distant one is " << number_of_steps << " steps away." << std::endl;
}
