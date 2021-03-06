/*
  Exercise taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Page 305

  A post office has a special room with shape of nxm matrix. On every field of the matrix there is 0 to 9 letters which postmen must deliver. Before delivering the letters, the postman
  enters the room with the intention of taking as much letters as possible by moving through the room either down or right. The postman starts from the upper left corner of the room
  and finishes taking the letters in the lower right corner of the room. What is the maximum number of letters the postman can take? The input data is n and m (1 <= n, m, 1000), then n
  rows which contain an array of m numbers x (0 <= x <= 9).

  The solution here is mine (prior to looking at the book's solution).
*/

#include <iostream>

using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  int input[n][m];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> input[i][j];
    }
  }
  int cumulative_sum[n][m];
  cumulative_sum[0][0] = input[0][0];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (((i - 1) < 0) && ((j - 1) < 0))
      {
	continue;
      }
      else if (((i - 1) >= 0) && ((j - 1) < 0))
      {
	cumulative_sum[i][j] = cumulative_sum[i - 1][j] + input[i][j];
      }
      else if (((i - 1) < 0) && ((j - 1) >= 0))
      {
	cumulative_sum[i][j] = cumulative_sum[i][j - 1] + input[i][j];
      }
      else if (((i - 1) >= 0) && ((j - 1) >= 0))
      {
	cumulative_sum[i][j] = max(cumulative_sum[i - 1][j], cumulative_sum[i][j - 1]) + input[i][j];
      }
    }
  }
  cout << cumulative_sum[n - 1][m - 1] << endl;
  return 0;
}
