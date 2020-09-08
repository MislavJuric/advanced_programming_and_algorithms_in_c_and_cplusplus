/*
  Exercise taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Page 318.

  A rabbit is running through a forrest of a rectangular shape. The forest has fields that you can walk through and fields on which there is stone.
  The rabbit can't move over the fields on which there is stone. On how many ways can the rabbit come from the upper left field of the forest to the
  lower right, if he is moving exclusively either down or right? The input data is n and m (1 <= n, m <= 1000), then n rows of m characters '.' or 'x'.
  '.' is the field which the rabbit can walk through and 'x' is the stone. Print out the remainder of dividing the number of ways on which the rabbit can come
  from the upper left corner of the forest to the lower right with 1000000.

  Note: It is possible that the number of ways is 0, because of the rocks. Upper left field and the lower right field will always be walkthrough -able.

  The solution here is the book's solution.
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> DP[2];
  DP[0].insert(DP[0].begin(), m, 0);
  DP[1].insert(DP[1].begin(), m, 0);
  string s;
  cin >> s;
  for (int i = 0; i < m && s[i] == '.'; i++)
  {
    DP[0][i] = 1;
  }
  for (int i = 1; i < n; i++)
  {
    cin >> s;
    for (int j = 0; j < m; j++)
    {
      if (s[j] == '.')
      {
	DP[i & 1][j] = DP[(i - 1) & 1][j] + (j ? DP[i & 1][j - 1] : 0); // (i & 1) is false for even numbers and is true for odd numbers - this way we alternate between 0 and 1
	DP[i % 1][j] %= 1000000;
      }
      else
      {
	DP[i & 1][j] = 0;
      }
    }
  }
  cout << DP[(n - 1) & 1][m - 1] << endl;
  return 0;
}
