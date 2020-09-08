/*
  Exercise taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Page 326

  Football club takes note of its financial gain and loss. Every week a number x is noted (-1000 <= x <= 1000) which represents gain or loss made
  over the last week. Club management wants to know the maximum amount the club earned in a certain interval. Input data is n (1 <= n <= 1000000)
  and then n numbers x (at least one x will be positive). Print out the biggest sum of some contingent numbers in a row.

  The solution here is my solution.
*/

#include <iostream>

using namespace std;

constexpr int INF = 1000000000;

int main()
{
  int n;
  cin >> n;
  int input[n];
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    input[i] = x;
  }
  int cumulative_sum[n];
  cumulative_sum[0] = input[0];
  for (int i = 1; i < n; i++)
  {
    cumulative_sum[i] = cumulative_sum[i - 1] + input[i];
  }
  int max = -INF;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      int curr = cumulative_sum[i] - cumulative_sum[j];
      if (curr > max)
      {
	max = curr;
      }
    }
  }
  cout << max << endl;
  return 0;
}
