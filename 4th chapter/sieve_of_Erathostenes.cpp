/*
  Implementation taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Page 146

  This implementation was generated after looking at the book's solution and translating the code from C to C++.
*/

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
  bool *primes;
  int n;
  int bound;
  cin >> n;
  primes = new bool[n];
  for (int i = 0; i < n; i++)
  {
    primes[i] = true; // assume all numbers are prime
  }

  // 0 and 1 are not prime
  primes[0] = primes[1] = 0;
  
  bound = sqrt(n);
  for (int i = 2; i <= bound; i++)
  {
    if(primes[i] == true)
    {
      // find all of the multiples of i
      for (int j = i * 2; j <= n; j += i)
      {
	primes[j] = false;
      }
    }
  }

  for (int i = 0; i <= n; i++)
  {
    if (primes[i] == true)
    {
      cout << i << endl;
    }
  }
  delete[] primes;
  return 0;
}
