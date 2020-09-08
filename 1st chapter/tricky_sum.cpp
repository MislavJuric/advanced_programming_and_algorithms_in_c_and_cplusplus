/*
  Exercise taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Page 43
  Exercise text translated from Croatian to English by me.

  Input x. Write out the sum of x and "inversed" x. For example, inversed 1234 is 4321.

  The solution below is mine, generated before looking at the book's solution.
 */

#include <iostream>

using namespace std;

int main()
{
  int x;
  cin >> x;
  int inverse_x = 0;
  int magnitude = 1;
  // count the number of digits and adjust the magnitude accordingly
  for (int i = x; i > 10; i /= 10)
  {
    magnitude *= 10;
  }
  // calculate the inverse number, keeping in mind that the highest mangitude is now associated with the rightmost digit
  for (int i = x; i > 0; )
  {
    inverse_x += (i % 10) * magnitude;
    i /= 10;
    magnitude /= 10;
  }
  cout << x + inverse_x << endl;
  return 0;
}
