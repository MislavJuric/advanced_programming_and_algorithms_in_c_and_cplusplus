/*
  Exercise taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Page 45
  Exercise text translated from Croatian to English by me.

  Input x (1 <= x <= 100), then x array elements. Rotate each element for one to the right.

  Example:

  1 2 3 4 5

  5 1 2 3 4

  The solution below is generated after looking at the book's solution and trying to recreate it myself.
 */

#include <iostream>

using namespace std;

int main()
{
  int x;
  int A[100];
  cin >> x;
  for (int i = 0; i < x; i++)
  {
    cin >> A[i];
  }
  int temp = A[x - 1];
  for (int i = x - 1; i > 0; i--)
  {
    A[i] = A[i - 1];
  }
  A[0] = temp;
  for (int i = 0; i < x; i++)
  {
    cout << A[i] << " ";
  }
  cout << endl;
  return 0;
}
