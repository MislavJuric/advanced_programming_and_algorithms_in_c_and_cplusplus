/*
  Exercise taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Page 317

  The stairwell is composed of n stairs. How many ways are there to climb from the bottom to the top of the stairwell if we can pick whether we want to climb 1 or 2 stairs
  at every single step. At the beginning we are in front of the first stair. The input data is n (2 <= n <= 1000000). We need to print out the remainder of the divison of
  the number of ways to climb the stairwell with 1000000 (because the number of ways to climb the stairwell can be very big).

  The solution here is the book's solution.
*/

#include <iostream>

using namespace std;

int main()
{
  int n;
  cin >> n;
  int dp0, dp1 = 1, dp2 = 2;
  for (int i = 3; i <= n; i++)
  {
    dp0 = dp1;
    dp1 = dp2;
    dp2 = (dp1 + dp0) % 1000000;
  }
  cout << dp2 << endl;
  return 0;
}
