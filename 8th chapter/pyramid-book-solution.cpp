/*
  Exercise taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Page 301

  n (1 <= n <= 1000) is inputted. In the enxt n rows there are positive integers such that in the xth row there are x numbers.
  The goal in that "pyramid" is to find a path from the top to the bottom, in which the sum of the numbers it the largerst
  and print out that path. We start in the first row (the top of the pyramid) and we can move only down or down-right.

  The solution here is the book's solution.
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n; cin >> n;
  vector<vector<int>> pyramid(n);
  for (int i = 0; i < n; i++)
  {
    pyramid.insert(pyramid[i].begin(), i + 1, 0); // compiler error here - this is copied from the book verbatim; the goal was to create a vector that was able to be filled in with input later
  }
  vector<vector<int>> DP, path;
  DP = pyramid; path = pyramid;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      cin >> pyramid[i][j];
    }
  }
  DP[0][0] = pyramid[0][0]; // initial state

  for (int i = 1; i < n; i++) // start from the second row
  {
    for (int j = 0; j <= i; j++)
    {
      if ((j - 1 >= 0) && (DP[i - 1][j - 1] + pyramid[i][j] > DP[i][j]))
      {
	 DP[i][j] = DP[i - 1][j - 1] + pyramid[i][j];
	 pyramid[i][j] = -1; // -1 means we got here from upper left
      }
      if ((j < i) && (DP[i - 1][j] + pyramid[i][j] > DP[i][j]))
      {
	DP[i][j] = DP[i - 1][j] + pyramid[i][j];
	pyramid[i][j] = 0; // 0 means we got here from above ("upper")
      }
    }
  }

  int x = 0;
  for (int i = 1; i < n; i++)
  {
    if (DP[n - 1][i] > DP[n - 1][x])
    {
      x = i;
    }
  }
  vector<int> solution;
  for (int i = n - 1; i >= 0; i--)
  {
    solution.push_back(pyramid[i][x]);
    x += path[i][x];
  }

  for (int i = n - 1; i >= 0; i--)
  {
    cout << solution[i] << " ";
  }
  return 0;
}
