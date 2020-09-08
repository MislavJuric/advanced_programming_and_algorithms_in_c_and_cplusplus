/*
  Exercise taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Pages 328

  An array of numbers is given. Find the longest ascending subarray (the elements of the subarray need not be subsequent).
  Input data is n (1 <= n <= 100000) and then n numbers x (-1000000 <= x <= 1000000).

  The solution here is mine. I modeled it after the book's solution description (and partial code). The book has other (more time efficient) solutions presented as well.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> input(n), DP(n, 1);
  for (int i = 0; i < n; i++)
  {
    cin >> input[i];
  }
  for (int k = 1; k < n; k++)
  {
    for (int i = 0; i < k; i++)
    {
      if (input[i] <= input[k])
      {
	DP[k] = max(DP[k], DP[i] + 1);
      }
    }
  }
  int max_len = 1;
  for (int i = 0; i < n; i++)
  {
    if (DP[i] > max_len)
    {
      max_len = DP[i];
    }
  }
  cout << max_len << endl;
  return 0;
}
