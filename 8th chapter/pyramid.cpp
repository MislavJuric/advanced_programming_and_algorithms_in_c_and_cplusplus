/*
  Exercise taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Page 301

  n (1 <= n <= 1000) is inputted. In the enxt n rows there are positive integers such that in the xth row there are x numbers.
  The goal in that "pyramid" is to find a path from the top to the bottom, in which the sum of the numbers it the largerst
  and print out that path. We start in the first row (the top of the pyramid) and we can move only down or down-right.

  The solution here is mine, before looking at the solution code (I did read the description of the solution in between the solution code and the problem text).

  Note: There's a bug here, but as of now I can't see where it is.
*/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<pair<int, int>> path; // path in coordinates
  int pyramid[n][n];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      pyramid[i][j] = -1;
    }
  }
  int count = 1;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < count; j++)
    {
      int x;
      cin >> x;
      pyramid[i][j] = x;
    }
    count++;
  }
  cout << "----------------------------------" << endl;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << pyramid[i][j] << " ";
    }
    cout << endl;
  }
  cout << "----------------------------------" << endl;
  int cumulative_sum[n][n];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cumulative_sum[i][j] = 0;
    }
  }
  count = 1;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < count; j++)
    {
      // check if the coordinates are legit
      if ((i - 1) < 0 || (j - 1) < 0)
      {
	continue;
      }
      
      // remember the sum
      cumulative_sum[i][j] = max(cumulative_sum[i - 1][j - 1], cumulative_sum[i - 1][j]) + pyramid[i][j];

      int x = -1;
      int y = -1;
      if (cumulative_sum[i - 1][j - 1] > cumulative_sum[i - 1][j])
      {
	x = i - 1;
	y = j - 1;
      }
      else
      {
	x = i - 1;
	y = j;
      }
      
      // remember the path
      path.push_back(make_pair(x, y));
    }
    count++;
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << cumulative_sum[i][j] << " ";
    }
    cout << endl;
  }
  cout << "----------------------------------" << endl;
  // push back the last element to path
  for (int i = (n - 1); i < n; i++)
  {
   int max = 0;
   int x = -1;
   int y = -1;
   for (int j = 0; j < n; j++)
   {
     if (cumulative_sum[i][j] > max)
     {
       max = cumulative_sum[i][j];
       x = i;
       y = j;
     }
   }
   path.push_back(make_pair(x, y));
  }
  for (int i = 0; i < path.size(); i++)
  {
   cout << pyramid[path[i].first][path[i].second] << " ";
  }
  cout << endl;
  return 0;
}
