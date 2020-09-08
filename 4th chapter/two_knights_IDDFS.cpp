/*
  Implementation taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Page 175

  Input the numbers a, b, c and d (1 <= a, b, c, d <= 8) which represent two locations of knights on a chessboard. Then input x (1 <= x < 10) and print 
  out the number of moves knight at the field (a, b) hast to take to come to the field (c, d).

  This is the solution taken from the book, using IDDFS.
*/

#include <iostream>

using namespace std;

int boundary, c, d;
int found = 0;

void traverse (int x, int y, int move)
{
  if ((x == c) && (y == d))
  {
    found = true;
  }
  if (x < 0 || x > 7 || y < 0 || y > 7)
  {
    return;
  }
  if (move > boundary)
  {
    return;
  }
  traverse(x - 1, y - 2, move + 1);
  traverse(x - 1, y + 2, move + 1);
  traverse(x + 1, y - 2, move + 1);
  traverse(x + 1, y + 2, move + 1);
  traverse(x - 2, y - 1, move + 1);
  traverse(x - 2, y + 1, move + 1);
  traverse(x + 2, y - 1, move + 1);
  traverse(x + 2, y + 1, move + 1);
}

int main()
{
  int a, b;
  cin >> a >> b >> c >> d;
  a--; b--; c--; d--; // adjusting the fields so that the first field is (0,0)
  for (boundary = 0; found == 0; boundary++)
  {
    traverse(a, b, 0);
  }
  cout << "You need a minimum of " << boundary << " moves." << endl;
  return 0;
}
