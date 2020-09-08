/*
  My implementation of Euclid's algorithm based on the description from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Pages 160-161
*/

#include <iostream>

using namespace std;

int main()
{
  int a, b;
  cin >> a >> b;
  while (a != b)
  {
    if (a >= b)
    {
      a -= b;
    }
    else
    {
      b -= a;
    }
  }
  cout << a << endl;
}
