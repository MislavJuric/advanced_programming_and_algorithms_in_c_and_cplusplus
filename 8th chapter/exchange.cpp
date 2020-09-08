/*
  Exercise taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Page 299

  The bank decided that in the next n days it will exhange the ratio of dollars to euros within its money exchange booths.
  You found out this classified information and you want to use it to make the most money. You have 1000 euros at your disposal.
  What is the maximum amount of euros you can have on n-th day if you can exchange your money from dollars to euros and vice versa every day?
  The input data is n (1 <= n <= 100 000), then n positive decimal numbers x. On each day 1 euro is worth x dollars. If x is 1.5, for example,
  that means that that day you can exchange 10 euros to 15 dollars and vice versa.

  The solution here is mine (before looking at the book's solution). I did read the text between the task description and the solution code.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  cin >> n;
  
  double D[n]; // maximum amount of money on day with index i (in dollars)
  double E[n]; // maximum amount of money on day with index i (in euros)
  double coef[n]; // coefficient that represents the ratio of dollars to euros for that day.

  // start conditions
  D[0] = 1000;
  E[0] = 0;
  // coef is irrelevant for the first day - in the book's solution there is a coefficient for the first day as well
  
  for (int i = 1; i < n; i++)
  {
    double x;
    cin >> x;
    coef[i] = x;
    D[i] = max(D[i - 1], (E[i - 1] * coef[i]));
    E[i] = max(E[i - 1], (D[i - 1] * (1 / coef[i])));
  }
  if (D[n - 1] > E[n - 1])
  {
    cout << "You can have at most " << (D[n - 1] * coef[n - 1]) << " euros at the end of n days." << endl;
  }
  else
  {
    cout << "You can have at most " << E[n - 1] << " euros at the end of n days." << endl;
  }
  return 0;
}
