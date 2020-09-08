/*
  Code taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Pages 164

  Write out all the permutations of an arbitrary array.

  This solution is taken from the book. I "translated" it to C++.
*/

#include <iostream>
#include <string>

using namespace std;

int nextPerm(string x)
{
  int i, j, mini;
  for (i = x.length() - 1; i >= 0; i--)
  {
    if (x[i] < x[i + 1])
    {
      break;
    }
  }
  if (i == -1)
  {
    return 0;
  }
  mini = i + 1;
  for (j = i + 2; j < x.length(); j++)
  {
    if ((x[j] < x[mini]) && (x[j] > x[i]))
    {
      mini = j;
    }
  }
  // fancy way of switching variable values
  x[i] ^= x[mini];
  x[mini] ^= x[i];
  x[i] ^= x[mini];
  for (i++; i < x.length(); i++)
  {
    for (j = i + 1; j < x.length(); j++)
    {
      if (x[j] < x[i])
      {
	x[i] ^= x[j];
	x[j] ^= x[i];
	x[i] ^= x[j];
      }
    }
  }
  return 1;
}

int main()
{
  string x = "01AX";
  cout << x << endl;
  while (nextPerm(x))
  {
    cout << x << endl;
  }
  return 0;
}
