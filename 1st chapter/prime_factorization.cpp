/*
  Exercise taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Page 46
  Exercise text translated from Croatian to English by me.

  Write the factorization of x to its prime factors (1 <= x <= 10000000)

  The solution below is generated before looking at the book's solution.
 */

// bug in here somewhere... I'll find out what it is

#include <iostream>
#include <cmath>

using namespace std;

bool IsPrime(int number)
{
  bool prime = true;
  for (int i = 2; i <= sqrt(number); i++)
  {
    if ((number % i) == 0)
    {
      prime = false;
    }
  }
  return prime;
}

int main()
{
  int x;
  cin >> x;
  if (x == 1)
  {
    cout << "1" << endl;
    return 0;
  }
  while (x > 1)
  {
    for (int i = 2; i <= x; i++)
    {
      if (IsPrime(i) == true)
      {
	while ((x % i) == 0)
	{
	  cout << i << " ";
	  x /= i;
	}
      }
    }
  }
  cout << endl;
  return 0;
}
