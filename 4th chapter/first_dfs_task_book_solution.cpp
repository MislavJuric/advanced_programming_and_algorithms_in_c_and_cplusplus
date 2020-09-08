/*
  Exercise taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Page 170

  Write out the steps needed to arrange a 2D array that is 2x3 to this:

  1 2 3
  4 5 6

  Use DFS for this.

  The solution here is the book's solution.
*/

#include <iostream>

using namespace std;

int mem[6][6][6][6][6][6];

int solve(int a, int b, int c, int d, int e, int f)
{
  if (mem[a][b][c][d][e][f])
  {
    return 0; // already been here
  }
  mem[a][b][c][d][e][f] = 1; // we are here now
  if ((a == 1) && (b == 2) && (c == 3) && (d == 4) && (e == 5) && (f == 6))
  {
    cout << endl << "1 2 3" << endl << "4 5 6" << endl;
    return 1;
  }
  if (solve(d,b,c,a,e,f) || // an ugly way of getting into adjecent states
      solve(a,e,c,d,b,f) ||
      solve(a,b,f,d,e,c) ||
      solve(b,a,c,d,e,f) ||
      solve(a,c,b,d,e,f) ||
      solve(a,b,c,e,d,f) ||
      solve(a,b,c,d,f,e))
  {
    cout << endl << a << " " << b << " " << c << endl << d << " " << e << " " << f << endl;
    return 1;
  }
  return 0;
}

int main()
{
  int a,b,c,d,e,f;
  cin >> a >> b >> c >> d >> e >> f;
  if (!solve(a,b,c,d,e,f))
  {
    cout << "No solutions exist" << endl;
  }
  return 0;
}
