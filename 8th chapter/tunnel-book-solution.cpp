/*
  Exercise taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Pages 303-305

  You are located in a long tunnel with 5 automobile lanes. In the tunnel there is your friend which told you which tracks will have automobiles driving on them in the next
  n (1 <= n <= 1000000) seconds. In the tunnel there is no room for you to get off the road. You want to be on the tracks where the automobiles don't drive so that you don't get run over.
  If in the 7th second there are cars on the 1st, 2nd, 3rd and 5th lane, then you want to be on the 4th lane, so that you don't get run over by a car.

  One constraint is that you can cross into the adjecent lane in one second. So that means that if you're on the 2nd lane in x-th second, you can be on the 1st, 2nd or the 3rd lane
  in the (x+1)-th second. Before the first car arrives, you can be on any lane. The input data is n and then n times of 5 characters which can be either '-' or 'x'. If in the i-th
  row of input it says '---xx', that means that in the i-th second the 4th and 5th lanes contain automobiles. At the beginning you can pick your lane. Print out the minimum number of times
  you will be run over.

  The solution here is taken from the book.
*/

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main()
{
  int n;
  cin >> n;
  string s;
  vector<int> DP(5), DPprevious(5);
  cin >> s; // input the first line
  for (int i = 0; i < 5; i++) // and initialize
  {
    DP[i] = (s[i] == 'x');
  }
  for (int i = 1; i < n; i++)
  {
    cin >> s;
    DPprevious = DP;
    for (int j = 0; j < 5; j++)
    {
      DP[j] = (s[j] == 'x') + DPprevious[j];
      if (j > 0)
      {
	DP[j] = min(DP[j], (s[j] == 'x') + DPprevious[j - 1]);
      }
      if (j < 4)
      {
	DP[j] = min(DP[j], (s[j] == 'x') + DPprevious[j + 1]);
      }
    }
  }
  cout << min(min(min(DP[0], DP[1]), min(DP[2],DP[3])), DP[4]);
  return 0;
}
