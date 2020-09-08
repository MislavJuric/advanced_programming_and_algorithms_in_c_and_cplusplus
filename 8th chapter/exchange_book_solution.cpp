/*
  Exercise taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Page 299

  The bank decided that in the next n days it will exhange the ratio of dollars to euros within its money exchange booths.
  You found out this classified information and you want to use it to make the most money. You have 1000 euros at your disposal.
  What is the maximum amount of euros you can have on n-th day if you can exchange your money from dollars to euros and vice versa every day?
  The input data is n (1 <= n <= 100 000), then n positive decimal numbers x. On each day 1 euro is worth x dollars. If x is 1.5, for example,
  that means that that day you can exchange 10 euros to 15 dollars and vice versa.

  The solution here is the book's solution.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<double> D(n + 1, 0);
  vector<double> E(n + 1, 0);
  vector<double> coef(n + 1, 0);
  E[0] = 1000;
  for (int i = 0; i < n; i++)
  {
    cin >> coef[i + 1];
  }
  for (int i = 1; i <= n; i++)
  {
    D[i] = max(D[i - 1], E[i - 1] * coef[i]);
    E[i] = max(E[i - 1], D[i - 1] * (1 / coef[i]));
  }
  cout << E[n] << endl;
  return 0;
}
