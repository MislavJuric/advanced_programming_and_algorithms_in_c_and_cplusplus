/*
  Exercise taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Page 97
  Exercise text translated from Croatian to English by me.

  Input n and then n positive integers. Print out the two maximum numbers. You can't use arrays.

  The solution below is mine, generated before looking at the book's solution.
 */

#include <iostream>

using namespace std;

int main()
{
  int n;
  int max;
  int secondMax;
  int temp;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> temp;
    if (temp >= max)
    {
      secondMax = max;
      max = temp;
    }
    else if (temp > secondMax)
    {
      secondMax = temp;
    }
  }
  cout << max << " " << secondMax << endl;
  return 0;
}
