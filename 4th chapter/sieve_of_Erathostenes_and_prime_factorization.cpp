/*
  Implementation taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Page 147

  This implementation was generated after looking at the book's solution and translating the code from C to C++.
*/

#include <iostream>

using namespace std;

int prime[1000000];

void factorize(int x)
{
  while (prime[x])
  {
    cout << prime[x] << " ";
    x /= prime[x];
  }
  cout << x << endl;
}

int main()
{
  int i, j;
  for (int i = 0; i < 1000000; i++)
  {
    prime[i] = 0; // 0 means prime
  }
  prime[0] = prime[1] = 1;
  for (int i = 2; i <= 1000; i++) // sieve of Erathostenes
  {
    if (prime[i] == 0)
    {
      for (j = i * 2; j < 1000000; j += i)
      {
	prime[j] = i; // we remember which number erased this prime number
      }
    }
  }

  factorize(123321);
  factorize(351333);
  factorize(1560);
  return 0;
}
