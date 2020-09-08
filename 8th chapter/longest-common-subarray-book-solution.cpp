/*
  Exercise taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Page 331-332

  Mirela works for a secret organization and needs to spot regularities between two arrays of data. The goal is to find the longest common subbarray
  among the two arrays of numbers. The subarrays don't necessarily have to contain subsequent input array elements. The input data is n and m 
  (1 <= n,m <= 1000). n is the length of the first array, m is the length of the second array. After that n integers are inputted and then m integers
  are inputted. Print out the longest common subarray length.

  The solution here is the book's solution. I'm not super-clear about the logic of the dynamic here.
*/

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> A(n), B(m, 0);
  vector<vector<int>> DP(n, B); // initialization
  for (int i = 0; i < n; i++)
  {
    cin >> A[i];
  }
  for (int i = 0; i < m; i++)
  {
    cin >> B[i];
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (i)
      {
	DP[i][j] = max(DP[i][j], DP[i - 1][j]);
      }
      if (j)
      {
	DP[i][j] = max(DP[i][j], DP[i][j - 1]);
      }
      if (A[i] == B[j])
      {
	DP[i][j] = max(DP[i][j], ((i && j) ? DP[i - 1][j - 1] : 0) + 1);
      }
    }
  }
  cout << DP[n - 1][m - 1] << endl;
  return 0;
}
