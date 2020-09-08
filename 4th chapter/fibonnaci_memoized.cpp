/*
  Implementation taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Page 156

  This implementation was generated after looking at the book's solution and translating the code from C to C++.
*/

#include <iostream>

using namespace std;

int numberOfCalls; // number of fibo() function calls
int mem[100];

int fibo(int x)
{
  numberOfCalls++;
  if (x == 1)
  {
    return 0;
  }
  if (x == 2)
  {
    return 1;
  }
  if (mem[x] != -1) // if it is already calculated
  {
    return mem[x];
  }

  mem[x] = fibo(x - 1) + fibo(x - 2); // otherwise calculate
  return mem[x]; // and return
}

int main()
{
  int i;
  for (i = 0; i < 100; i++)
  {
    mem[i] = -1; // -1 means not calculated
  }
  cout << fibo(12) << endl;
  cout << numberOfCalls << endl;
  return 0;
}
