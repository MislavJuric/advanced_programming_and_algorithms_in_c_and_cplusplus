/*
  Task text taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Page 176

  Solve a 3x3 puzzle using a minimum number of moves. During that print all states of the puzzle in reverse order. Puzzle 3x3 needs to be folded in the following shape:

  1 2 3
  4 5 6
  7 8 9

  You can use 4 diffent types of rotations. With a rotation 4 nubmers which are adjecent to each other (2x2 square) are replaced in a clockwise direction.

  I.e. from:

  9 8 7
  6 5 4
  3 2 1

  you can go to:
  
  6 9 7    9 5 8    9 8 7    9 8 7
  5 8 4    6 4 7    3 6 4    6 2 5
  3 2 1    3 2 1    2 5 1    3 1 4

  This solution is mine; I wrote it before looking at the book's solution. The book suggested using IIDFS, so I used that.
*/

#include <iostream>

using namespace std;

int boundary = 0;
bool solved = false;

bool solve(int a, int b, int c, int d, int e, int f, int g, int h, int i, int move)
{
  if (move > boundary)
  {
    return 0;
  }
  if ((a == 1) && (b == 2) && (c == 3) && (d == 4) && (e == 5) && (f == 6) && (g == 7) && (h == 8) && (i == 9))
  {
    solved = true;
    cout << "1 2 3" << endl << "4 5 6" << endl << "7 8 9" << endl << endl;
    return 1;
  }
  if (solve(d, a, c, e, b, f, g, h, i, move + 1) ||
      solve(a, e, b, d, f, c, g, h, i, move + 1) ||
      solve(a, b, c, g, d, f, h, e, i, move + 1) ||
      solve(a, b, c, d, h, e, g, i, f, move + 1))
  {
    cout << a << " " << b << " " << c << endl << d << " " << e << " " << f << endl << g << " " << h << " " << i << endl << endl;
    return 1;
  }
  return 0;
}

int main()
{
  int a, b, c, d, e, f, g, h, i;
  cin >> a >> b >> c >> d >> e >> f >> g >> h >> i;
  cout << endl;
  for (boundary = 0; solved != true; boundary++) // this part is the iterative part in the IIDFS; it increases the boundary progressively, so that we know we have the shortest possible solution of this task
  {
    solve(a, b, c, d, e, f, g, h, i, 0);
  }
  return 0;
}
