/*
  Exercise taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Pages 171-172

  n and m (1 <= n,m <= 50) are inputted and then n rows with m characters each (just 'x' and '.'). Inputted characters describe a land whose edges must be surrounded by 'x' characters.
  'x' represents a rock and a '.' represents fertile soil. After we input the land described by those two characters we input two numbers which represent the row and the column
  of the land (where there is no rock) and there we plant the grass. Construct a program that replaces all '.' characters with '+' characters if grass can be spread on that place.
  Grass is spread on adjecent fields where the soil is fertile (adjecent fields share an adjecent edge). Write out the look of the land after the grass proliferates as much as possible.

  The solution generated here is mine, before looking at the book's solution.
*/

#include <iostream>

using namespace std;

char land[50][50]; // maximum size, as defined in the task text
int n, m; // actual size

void proliferateGrass(int row, int column)
{
  // boundary conditions check
  if ((row < 0) || (row >= n) || (column < 0) || (column >= m))
  {
    return;
  }
  // check if the soil is fertile and if it is, plant the grass here
  if (land[row][column] == '.')
  {
    land[row][column] = '+';
    // check the adjecent positions
    proliferateGrass(row + 1, column);
    proliferateGrass(row - 1, column);
    proliferateGrass(row, column + 1);
    proliferateGrass(row, column - 1);
  }
  // soil is infertile, don't spread grass
  else
  {
    return;
  }
}

int main()
{
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> land[i][j];
    }
  }
  int initial_grass_row, initial_grass_column;
  cin >> initial_grass_row >> initial_grass_column;
  proliferateGrass(initial_grass_row, initial_grass_column);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << land[i][j];
    }
    cout << endl;
  }
}
