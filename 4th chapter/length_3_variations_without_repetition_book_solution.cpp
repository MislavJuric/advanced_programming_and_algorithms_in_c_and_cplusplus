/*
  Task text taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Page 158

  Write out all the variations without repetition of the numbers 1, 2, 3, 4 and 5 of length 3.

  This solution is taken from the book.
*/

// I traced this through on paper since it was hard for me to understand it immediately; it makes sense

#include <iostream>

constexpr int MAXI = 5;

using namespace std;

void rec(int x, int n)
{
  int digits[MAXI] = {0}; // we are using the elements at the 0 to 4 indicies
  int xx, i;
  if (n == 0)
  {
    cout << x << endl;
    return;
  }
  xx = x;
  while (xx)
  {
    digits[xx % 10 - 1] = 1; // so it is between 0 and 4
    xx /= 10;
  }
  for (i = 1; i <= MAXI; i++)
  {
    if (!digits[i - 1])
    {
      rec(x * 10 + i, n - 1);
    }
  }
}

int main()
{
  rec(0,3);
  return 0;
}
